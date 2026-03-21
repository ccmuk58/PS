#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

struct Point
{
	ll x, y;
	auto operator<=>(const Point&) const = default;
};

Point p1,p2,p3,p4;

ll ccw(Point a, Point b, Point c)
{
	Point v1 = {b.x-a.x, b.y-a.y};
	Point v2 = {c.x-b.x, c.y-b.y};
	ll w = v1.x*v2.y - v1.y*v2.x;
	if(w < 0) return -1;	// cw
	else if(w > 0) return 1; // ccw
	else return 0;	// 일직선
}
ll ans=0;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;
	cin >> p4.x >> p4.y;

	ll a = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll b = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if(a==0 && b==0)
	{
		if(p1>p2) swap(p1, p2);
		if(p3>p4) swap(p3, p4);
		if(p3<=p2 && p1<=p4)
			ans=1;
	}
	else if(a<=0 && b<=0)
		ans=1;
		
	cout << ans;

}