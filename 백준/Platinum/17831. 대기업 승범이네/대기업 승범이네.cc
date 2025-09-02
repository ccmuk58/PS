#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int MOD = 1e9 + 7;
constexpr int LMT = 2e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll dp[LMT][2] = {};
vector<int> g[LMT];
ll skill[LMT];

void go(int n)
{
	if(g[n].size()==0)
		return;

	for(int i=0; i<g[n].size(); i++)
	{
		go(g[n][i]);
		dp[n][0] += max(dp[g[n][i]][0], dp[g[n][i]][1]);
	}
	for(int i=0; i<g[n].size(); i++)
	{
		if(dp[g[n][i]][0] > dp[g[n][i]][1])
		{
			dp[n][1] = max(dp[n][1], dp[n][0]+skill[n]*skill[g[n][i]]);
		}
		else
		{
			dp[n][1] = max(dp[n][1], dp[n][0] + skill[n]*skill[g[n][i]] - dp[g[n][i]][1] + dp[g[n][i]][0]) ;
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	ll ans = 0;
	vector<ll> v;
	
	int st = 0;
	for(int i=2; i<=N; i++)
	{
		cin >> A;
		g[A].push_back(i);
	}

	for(int i=1; i<=N; i++)
	{
		cin >> A;
		skill[i] = A;
	}
	go(1);
	cout << max(dp[1][1], dp[1][0]);


}