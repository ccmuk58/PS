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

ll dp[1002][1002];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
	for(int i=0; i<=N; i++)
	{
		dp[i][0]=1;
		dp[i][i]=1;
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=K; j++)
		{
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
		}
	}
	cout << dp[N][K];
}