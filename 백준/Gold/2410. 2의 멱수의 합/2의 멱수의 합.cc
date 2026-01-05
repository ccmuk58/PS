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
	
	cin >> N;
	vector<ll> v;
	ll ans = 0;
	ll dp[N+2]={};

	dp[1] = 1;
	for(int i=2; i<=N; i++)
	{
		if(i%2)
			dp[i] = dp[i-1];
		else
			dp[i] = (dp[i-1] + dp[i/2])%1000000000;
	}
	cout << dp[N];

}