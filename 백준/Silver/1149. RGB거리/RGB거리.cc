#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	int cost[3];
	int dpCost[1000][3];

	cin >> N;
	for (int j = 0; j < 3; j++)
	{
		cin >> cost[j];
		dpCost[0][j] = cost[j];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> cost[j];
		for (int j = 0; j < 3; j++)
		{
			int minCost = INT_MAX;
			for (int k = 0; k < 3; k++)
			{
				if (j == k) continue;
				minCost = min(minCost, cost[j] + dpCost[i - 1][k]);
			}
			dpCost[i][j] = minCost;
		}
	}
	int minDp = INT_MAX;
	for (int j = 0; j < 3; j++)
		minDp = min(minDp, dpCost[N - 1][j]);

	cout << minDp;
}