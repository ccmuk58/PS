#include <bits/stdc++.h>
using namespace std;
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

ll dp[LMT][3];
ll ans;
char c[LMT];

ll p(ll n)
{
	ll x = 2;
	ll res = 1;
	while(n)
	{
		if(n&1)
		{
			res *= x;
			res %= MOD;
		}

		x=(x*x)%MOD;
		n = n>>1;
	}
	return res % MOD;

}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

	for(int i=0; i<N; i++)
		cin >> c[i];

	for(int i=N-1; i>=0; i--)
	{
		for(int j=0; j<3; j++)
			dp[i][j] = dp[i+1][j] % MOD;

		if(c[i]=='R')
			ans += (p(i) * dp[i][0])%MOD;
		else if(c[i]=='O')
			dp[i][0] += (dp[i][1]);
		else if(c[i]=='C')
			dp[i][1] += (dp[i][2]);
		else if(c[i]=='K')
			dp[i][2] += 1;

		for(int j=0; j<3; j++)
			dp[i][j] %= MOD;

		ans %= MOD;
	}

	cout << ans;

}