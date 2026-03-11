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
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	ll dp[N+2][2] = {};
	ll v[N+2]={};
	ll ans = -2000;
	for(int i=0; i<N; i++)
	{
		cin >> v[i];
		ans=max(ans, v[i]);
	}

	if(N==1)
	{
		cout << v[0];
		return 0;
	}

	dp[0][0] = v[0];
	dp[0][1] = v[0];
	for(int i=1; i<N; i++)
	{
		dp[i][0] = max(dp[i-1][0]+v[i], v[i]);
		dp[i][1] = max(dp[i-1][1]+v[i], dp[i-1][0]);
	}

	for(int i=0; i<N; i++)
	{
		ans = max(ans,dp[i][0]);
		ans = max(ans,dp[i][1]);
	}
	cout << ans;
}