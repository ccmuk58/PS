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
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll dp[100002][3];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

	for(int i=0; i<3; i++)
		dp[1][i] =1;

	for(int i=2; i<=N; i++)
	{
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]*2)%9901;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1])%9901;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1])%9901;
	}
	ll ans = (dp[N][0] + dp[N][1] + dp[N][2])%9901;
	cout << ans;
}