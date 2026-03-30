#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e9 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
struct Point{
	ll x, y;	
	auto operator<=>(const Point& other) const = default;
};
struct Line{
	Point a, b;
	auto operator<=>(const Line& other) const = default;
};
Point operator + (Point l, Point r){ return Point(l.x + r.x, l.y + r.y); }
Point operator - (Point l, Point r){ return Point(l.x - r.x, l.y - r.y); }
ll operator * (Point l, Point r){ return (ll)l.x * r.x + (ll)l.y * r.y; }
ll operator / (Point l, Point r){ return (ll)l.x * r.x - (ll)l.y * r.y; }

ll ccw(Point a, Point b, Point c)
{
	Point v1 = {b.x-a.x, b.y-a.y};
	Point v2 = {c.x-b.x, c.y-b.y};
	ll w = v1.x*v2.y - v1.y*v2.x;
	if(w < 0) return -1;	// cw
	else if(w > 0) return 1; // ccw
	else return 0;	// 일직선
}

vector<Point> inP, outP, signP;

bool isInside(Point p, const vector<Point>& polygon, ll n)
{
	ll l = 0;
	ll r = n-1;
	ll mid = (l+r)>>1;

	Point st = polygon[0];
	while(l<r)
	{

		mid = (l+r)>>1;
		Line lline(st, polygon[mid]);
		Line mline(polygon[mid], polygon[mid+1]);
		Line rline(polygon[mid+1], st);

		ll a = ccw(lline.a, lline.b, p);
		ll b = ccw(mline.a, mline.b, p);
		ll c = ccw(rline.a, rline.b, p);
		if(a==b && a==c)
        {
            return true;
        }
		if(a==0 && b==c)
		{
            return true;
		}
		if(b==0 && a==c)
		{
            return true;
		}
		if(c==0 && b==a)
		{
            return true;
		}

        if(b==c)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return false;
	
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	ll ans = 0;

	// out, in, sign
	cin >> N >> M >> K;

	for(int i=0; i<N; i++)
	{
		cin >> X >> Y;
		outP.push_back({X,Y});
	}
	for(int i=0; i<M; i++)
	{
		cin >> X >> Y;
		inP.push_back({X,Y});
	}
	for(int i=0; i<K; i++)
	{
		cin >> X >> Y;
		signP.push_back({X,Y});
	}

	for(const Point& p : signP)
	{
		if(!isInside(p, outP, N) || isInside(p, inP, M))
		{
			ans++;
		}
	}
	
	if(ans>0)
		cout << ans;
	else
		cout << "YES";

}