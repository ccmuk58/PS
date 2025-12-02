#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using plp = pair<ll, pl>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = INT64_MAX;

int v[100002];
int dp[100002];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	int ans = -1000000;
	for(int i=1; i<=N; i++)
	{
		cin >> v[i];
		ans = max(ans, v[i]);
	}

	for(int i=1; i<=N; i++)
	{
		dp[i] = max(dp[i-1]+v[i], v[i]);
		ans = max(dp[i], ans);
	}

	
    cout << ans;
}