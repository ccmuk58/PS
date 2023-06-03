#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 1000002;

vector<int> graph[LIMIT];
int dp[LIMIT][2];

void find(int cur, int pre)
{
	dp[cur][0] = 0;
	dp[cur][1] = 1;

	for (int next : graph[cur])
	{
		if (next == pre)continue;
		find(next, cur);
		dp[cur][0] += dp[next][1];
		dp[cur][1] += min(dp[next][1], dp[next][0]);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for(int i=0; i<N-1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	find(1, -1);
	cout << min(dp[1][0], dp[1][1]);
}