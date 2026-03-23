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
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll par[3002];
ll lv[3002];
ll maxg = 0;
ll gCnt;

struct Point{
	ll x, y;	

	auto operator<=>(const Point& other) const = default;
};
struct Line{
	Point a, b;
	auto operator<=>(const Line& other) const = default;
};
ll ccw(Point a, Point b, Point c)
{
	Point v1 = {b.x-a.x, b.y-a.y};
	Point v2 = {c.x-b.x, c.y-b.y};
	ll w = v1.x*v2.y - v1.y*v2.x;
	if(w < 0) return -1;	// cw
	else if(w > 0) return 1; // ccw
	else return 0;	// 일직선
}

ll find(ll n)
{
	if(n==par[n]) return n;

	return par[n] = find(par[n]);
}
void uni(ll a, ll b)
{
	a = find(a);
	b = find(b);

	if(a==b) return;

	if(lv[b]>lv[a]) swap(a, b);
	par[b] = a;
	lv[a] += lv[b]+1;
	maxg = max(maxg, lv[a]);
	gCnt--;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	vector<Line> lines;
	gCnt=N;

	iota(par, par+3001, 0);
	for(int i=0; i<N; i++)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		lines.push_back({x1, y1, x2, y2});
		if(lines[lines.size()-1].a > lines[lines.size()-1].b)
		{
			swap(lines[lines.size()-1].a, lines[lines.size()-1].b);
		}
	}
	sort(lines.begin(), lines.end());

	for(int i=0; i<N-1; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(par[i]==par[j]) continue;
			Line &l1 = lines[i];
			Line &l2 = lines[j];
            ll a = ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b);
            ll b = ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b);

			if(a==0 && b==0)
			{
				
				if(l1.a>l1.b) swap(l1.a,l1.b);
				if(l2.a>l2.b) swap(l2.a, l2.b);
				if(l2.a<=l1.b && l1.a<=l2.b)
					uni(i, j);
			}
			else if(a<=0 && b<=0)
			{
				uni(i, j);
			}

        }
	}

	cout << gCnt << "\n" << maxg+1;

}