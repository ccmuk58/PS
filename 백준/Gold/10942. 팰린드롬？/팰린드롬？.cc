#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
constexpr int MAX = 2000 + 1;
constexpr int INF = 1e9 + 1;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n;

	int arr[n+1]={};
	int dp[n+1][n+1]={};
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i][i] = 1;
	}
	for(int i = 1; i <= n-1; i++)
	{
		if(arr[i] == arr[i+1])
			dp[i][i+1] = 1;
	}
	for(int len = 2; len <= n-1; len++)
	{
		for(int s = 1; s <= n-len; s++)
		{
			if(arr[s] == arr[s+len] && dp[s+1][s+len-1] == 1)
				dp[s][s+len] = 1;
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}