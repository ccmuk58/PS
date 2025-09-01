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
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll dp[LMT] = {};
vector<int> g[LMT];

int sub(int n)
{
	dp[n] = 1;
	for(int i=0; i<g[n].size(); i++)
	{
		if(dp[g[n][i]] != 0) 
			continue;
		dp[n] += sub(g[n][i]);
	}
	return dp[n];
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	ll ans = 0;
	vector<ll> v;
	
	for(int i=0; i<N-1; i++)
	{
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	for(int i=0; i<N-1; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end());

	sub(1);
	for(int i=1; i<=N; i++)
	{
		dp[i] *= (N-dp[i]);
		dp[i]%MOD;
	}
	sort(dp+1, dp+N+1, greater<>());
	for(int i=1; i<=N; i++)
	{
		ans += (dp[i]*v[i-1])%MOD;
		ans%=MOD;
	}

	cout << ans;


}