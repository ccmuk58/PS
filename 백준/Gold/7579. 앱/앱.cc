#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll ans = 100000;
vector<ll> v;

ll dp[102][10002] = {};
ll mem[102] = {};
ll cost[102] = {};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		cin >> A;
		mem[i] = A;
	}
	for(int i=1; i<=N; i++)
	{
		cin >> A;
		cost[i] = A;
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=0; j<=10000; j++)
		{
			if(j<cost[i])
			{
				dp[i][j] = dp[i-1][j];
				continue;
			}

			dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+mem[i]);
			if(dp[i][j] >= M)
			{
				ans = min(ans, (ll)j);
			}
		}
	}
	cout << ans;

}