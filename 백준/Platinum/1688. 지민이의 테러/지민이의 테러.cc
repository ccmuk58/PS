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
ll getDistance(Point a, Point b)
{
	return sqrt(pow(b.x-a.x, 2) + pow(b.y-b.x, 2));
}
ll ccw(Point a, Point b, Point c)
{
	Point v1 = {b.x-a.x, b.y-a.y};
	Point v2 = {c.x-b.x, c.y-b.y};
	ll w = v1.x*v2.y - v1.y*v2.x;
	if(w < 0) return -1;	// cw
	else if(w > 0) return 1; // ccw
	else return 0;	// 일직선
}
Point operator + (Point l, Point r){ return Point(l.x + r.x, l.y + r.y); }
Point operator - (Point l, Point r){ return Point(l.x - r.x, l.y - r.y); }
ll operator * (Point l, Point r){ return (ll)l.x * r.x + (ll)l.y * r.y; }
ll operator / (Point l, Point r){ return (ll)l.x * r.x - (ll)l.y * r.y; }

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	vector<Point> p;
	vector<Line> l;
	ll ans = 0;

	for(int i=0; i<N; i++)
	{
		cin >> X >> Y;
		p.push_back({X,Y});
		if(i>0)
		{
			l.push_back({p[i-1], p[i]});
		}
	}
	l.push_back({p[0], p[N-1]});

	for(int i=0; i<3; i++)
	{
		cin >> X >> Y;
		Line tl({X,Y}, {LMT, Y+1});
		ll cnt = 0;
		for(int i=0; i<N; i++)
		{
			Line l1 = tl;
			Line l2 = l[i];
			ll a = ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b);
			ll b = ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b);

			if(a==0)
			{
				if((l1.a >= l2.a && l1.a <= l2.b) || (l1.a >= l2.b && l1.a <= l2.a))
				{
					cnt = 1;
					break;
				}
			}
			else if(a<=0 && b<=0)
			{
				cnt++;
			}
			
			/*
			auto [x1, y1] = l1.a;
			auto [x2, y2] = l1.b;
			auto [x3, y3] = l2.a;
			auto [x4, y4] = l2.b;
			Point v1 = l1.b - l1.a;
			Point v2 = l2.b - l2.a;
			auto [d1x, d1y] = v1;
			auto [d2x, d2y] = v2;
			ll num = x3*d1y-d1y-y3*d1x-y1*d1x;
			ll denom = d2y*d1x-d2x*d1y;
			double s = num/denom;
			if(denom==0&&(l1.a==l2.a||l1.a==l2.b))
			{
				
			}
			else
			{
				cnt++;
			}
			*/
		}
		
		cout << (cnt&1) << "\n";
	}


}