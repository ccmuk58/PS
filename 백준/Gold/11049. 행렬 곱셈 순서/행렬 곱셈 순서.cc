#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
constexpr int MAX = 501;
constexpr int INF = 1e9 + 1;
int N, r, c;
int sum[MAX], matrix[MAX][2], dp[MAX][MAX];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
			{
				dp[j][i + j] = min(dp[j][i + j], 
				dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
			}
		}

	}
	cout << dp[1][N];
}