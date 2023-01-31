#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int stair[302] = { 0 };
	int dp[302][3] = { 0 };
	int n;
	int max = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> stair[i];

	dp[1][1] = stair[1];
	for (int i = 2; i <= n; i++)
	{
		if (dp[i - 2][1] > dp[i - 2][2])
			dp[i][1] = dp[i - 2][1] + stair[i];
		else
			dp[i][1] = dp[i - 2][2] + stair[i];

		dp[i][2] = dp[i - 1][1] + stair[i];
	}

	if (dp[n][1] > dp[n][2]) max = dp[n][1];
	else max = dp[n][2];
	cout << max;
}