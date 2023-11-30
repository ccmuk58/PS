#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

int cost[1001][4];
int dp[1001][4];
int main() {
    cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=3; j++)
			cin >> cost[i][j];

	int minDp = 1e9;
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(i==j) dp[1][j] = cost[1][j];
			else dp[1][j] = 1e9;
		}
		for(int j=2; j<=n; j++)
		{
			dp[j][1] = min(dp[j-1][2], dp[j-1][3]) + cost[j][1];
			dp[j][2] = min(dp[j-1][1], dp[j-1][3]) + cost[j][2];
			dp[j][3] = min(dp[j-1][1], dp[j-1][2]) + cost[j][3];
		}
		for(int j=1; j<=3; j++)
		{
			if(i==j) continue;
			minDp = min(minDp, dp[n][j]);
		}
	}

	cout << minDp;
}