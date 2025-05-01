#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int dp[4002][4002] = {};
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	string a, b;
	cin >> a >> b;


	int ans = 0;
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]==b[0]) dp[i][0] = 1;
		ans = max(ans, dp[i][0]);
	}
	for(int i=0; i<b.length(); i++)
	{
		if(a[0]==b[i]) dp[0][i] = 1;
		ans = max(ans, dp[0][i]);
	}
	for(int i=1; i<a.length(); i++)
	{
		for(int j=1; j<b.length(); j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
		
	}
	cout << ans;

}