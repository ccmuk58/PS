#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

pl p1, p2;
pl p3, p4;

ll ccw(pl a, pl b, pl c)
{
	pl v1 = {b.first-a.first, b.second-a.second};
	pl v2 = {c.first-b.first, c.second-b.second};
	ll w = v1.first*v2.second - v1.second*v2.first;
	if(w>0) return 1;
	else if(w<0) return -1;
	else return 0;
}
ll ans=0;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;
	cin >> p4.first >> p4.second;

	ll a = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll b = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if(a<=0 && b<=0)
	{
		ans=1;
	}
	cout << ans;

}