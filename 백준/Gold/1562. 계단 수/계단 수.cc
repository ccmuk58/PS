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
constexpr ll MOD = 1e9;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
	ll dp[102][11][1025] = {};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	ll ans = 0;
	// [완성된 자릿수][마지막 숫자][사용한숫자 bitmask]
	
	for(int i=1; i<=9; i++)
	{
		dp[1][i][1<<i] = 1;
	}

	for(ll i=2; i<=N; i++)
	{
		for(ll j=0; j<=9; j++)
		{
			for(ll k=0; k < (1<<10); k++)
			{
				ll nk = k|(1<<j);
				if(j==0)
				{
					dp[i][j][nk] =  (dp[i][j][nk]+dp[i-1][j+1][k]%MOD)%MOD;
				}
				else if(j==9)
				{
					dp[i][j][nk] =  (dp[i][j][nk]+dp[i-1][j-1][k]%MOD)%MOD;
				}
				else
				{
					dp[i][j][nk] =  (dp[i][j][nk]+dp[i-1][j-1][k]%MOD+dp[i-1][j+1][k]%MOD)%MOD;
				}
			}
		}
	}

	for(int i=0; i<=9; i++)
	{
		ans += dp[N][i][(1<<10)-1];
		ans %= MOD;
	}
	cout << ans;

}