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
Point operator + (const Point& l, const Point& r){ return Point(l.x + r.x, l.y + r.y); }
Point operator - (const Point& l, const Point& r){ return Point(l.x - r.x, l.y - r.y); }
ll operator * (const Point& l, const Point& r){ return (ll)l.x * r.x + (ll)l.y * r.y; }
ll operator / (const Point& l, const Point& r){ return (ll)l.x * r.x - (ll)l.y * r.y; }
ll dist(const Point& a, const Point& b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
ll ccw(Point a, Point b, Point c)
{
	Point v1 = {b.x-a.x, b.y-a.y};
	Point v2 = {c.x-b.x, c.y-b.y};
	ll w = v1.x*v2.y - v1.y*v2.x;
	if(w < 0) return -1;
	else if(w > 0) return 1;
	else return 0;
}

Point stp;
bool yxCmp(const Point& a, const Point& b) 
{
	return a.y==b.y ? a.x<=b.x : a.y<b.y;
}
bool angleCmp(const Point& a, const Point& b) 
{
	ll c = ccw(stp, a, b);
	if(c==0)
	{
		return dist(stp,a) <= dist(stp,b);
	}
	return c>0;
}

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
	}
	sort(p.begin(), p.end(), yxCmp);
	stp = p[0];
	sort(p.begin()+1, p.end(), angleCmp);
	p.push_back(stp);

	stack<Point> s;
	s.push(p[0]);
	s.push(p[1]);
	for(int i=2; i<N+1; i++)
	{
		if(s.size()<2)
		{
			s.push(p[i]);
			continue;
		}
		Point b = s.top();
		s.pop();
		Point a = s.top();
		if(ccw(a,b,p[i])>0)
		{
			s.push(b);
			s.push(p[i]);
		}
		else
		{
			i--;
		}
	}
	cout << s.size()-1;

}