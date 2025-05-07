#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	ll dp[1005][2] = {};
	dp[1][0] = 1;
	dp[1][1] = 0;
	for(int i=1; i<=N; i++)
	{
		ll cur = 
		dp[i+1][0] += dp[i][0];
		dp[i+1][0] %= MOD;
		dp[i+1][1] += dp[i][1];
		dp[i+1][1] %= MOD;
		
		
		dp[i+2][0] += dp[i][0];
		dp[i+2][0] %= MOD;
		dp[i+2][1] += dp[i][0] + dp[i][1]*2;
		dp[i+2][1] %= MOD;
		
		dp[i+3][0] += dp[i][0];
		dp[i+3][0] %= MOD;
		dp[i+3][1] += dp[i][0]*2 + dp[i][1]*3;
		dp[i+3][1] %= MOD;
	}

	cout << dp[N+1][1];
}