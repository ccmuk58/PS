#include<iostream>
using namespace std;
constexpr int LIMIT = 102;

int n;
int k;
int coin[LIMIT];
int dp[LIMIT*LIMIT];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
}