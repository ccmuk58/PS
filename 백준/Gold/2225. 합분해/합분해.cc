#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	ll dp[N+2][K+2] = {};

	for(int i=1; i<=N; i++)
		dp[i][1] = 1;
	for(int i=1; i<=K; i++)
		dp[1][i] = i;

	for(int i=2; i<=N; i++)
	{
		for(int j=2; j<=K; j++)
		{
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000000;
		}
	}

	cout << dp[N][K];
}