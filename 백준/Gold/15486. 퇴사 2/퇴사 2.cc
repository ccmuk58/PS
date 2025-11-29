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
ll ans = 0;
ll dp[1500200];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	vector<pi> v;
	for(int i=1; i<=N; i++)
	{
		cin >> A >> B;
		v.push_back({A,B});
	}
	for(int i=0; i<N; i++)
	{
		dp[i+v[i].first] = max(dp[i+v[i].first], dp[i]+v[i].second);
		for(int j=0; j<50; j++)
		{
			dp[i+v[i].first+j] = max(dp[i+v[i].first+j], dp[i+v[i].first]);
		}
	}

	
	cout << dp[N];

}