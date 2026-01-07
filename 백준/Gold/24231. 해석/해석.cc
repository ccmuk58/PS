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

ll dp[302][302] = {};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	vector<ll> v;
	ll ans = 0;
	string s;

	cin >> s;
	for(int i=1; i<=s.length(); i++)
	{
		dp[i][i - 1] = 1;
	}

	for(int len=2; len<=s.length(); len++)
	{
		for(int left=0; left<=s.length()-len; left++)
		{
			int right = left+len-1;
			for(int k=left+1; k<=right; k++)
			{
				if (s[left] == s[k]) continue;
				dp[left][right] = (dp[left][right] + dp[left + 1][k - 1] * dp[k + 1][right]) % MOD;
			}
		}
	}

	cout << dp[0][s.length()-1];
	

}

/*
001011
*/