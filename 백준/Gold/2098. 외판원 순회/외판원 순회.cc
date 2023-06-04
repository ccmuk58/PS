#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 17;
constexpr int INF = 1e9;

int graph[LIMIT][LIMIT];
int dp[LIMIT][(1<<(LIMIT-1))];
int N;

int travel(int cur, int vBit)
{
	if (vBit == (1 << N) - 1)
	{
		if (!graph[cur][0])	return INF;
		return graph[cur][0];
	}
	if (dp[cur][vBit]) return dp[cur][vBit];

	dp[cur][vBit] = INF;
	for (int i = 0; i < N; i++)
	{
		int next = 1 << i;
		if (!graph[cur][i]) continue;
		if ((vBit & next) > 0) continue;
		dp[cur][vBit] = min(dp[cur][vBit], travel(i, vBit | next) + graph[cur][i]);
	}
	return dp[cur][vBit];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
	
	cout << travel(0, 1<<0);

}