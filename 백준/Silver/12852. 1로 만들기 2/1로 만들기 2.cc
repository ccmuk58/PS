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
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int dp[LMT];
int path[LMT];

void solve()
{
	for(int i=2; i<=N; i++)
	{
		if(dp[i] > dp[i-1]+1)
		{
			dp[i] = dp[i-1]+1;
			path[i] = i-1;
		}
		if(i%2==0 && dp[i] > dp[i/2]+1) 
		{
			dp[i] = dp[i/2]+1;
			path[i] = i/2;
		}
		if(i%3==0 && dp[i] > dp[i/3]+1) 
		{
			dp[i] = dp[i/3]+1;
			path[i] = i/3;
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	fill(dp, dp+LMT, INT32_MAX);
	dp[1] = 0;
	solve();

	cout << dp[N] <<"\n";
	int idx = N;
	for(int i=0; i<=dp[N]; i++)
	{
		cout << idx << " ";
		idx = path[idx];
	}
}