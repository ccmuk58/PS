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
	
	cin >> T;
	ll dp[100002][4] = {};

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for(int i=4; i<=100000; i++)
	{
		dp[i][1] = (dp[i-1][2]+dp[i-1][3])%1000000009;
		dp[i][2] = (dp[i-2][1]+dp[i-2][3])%1000000009;
		dp[i][3] = (dp[i-3][2]+dp[i-3][1])%1000000009;
	}
	while(T--)
	{
		cin >> A;
		cout << (dp[A][1]+dp[A][2]+dp[A][3])%1000000009 << "\n";
	}
}