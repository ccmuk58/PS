#include <bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 500 + 2;
constexpr int dy[] = {-1, 1, 0, 0};
constexpr int dx[] = {0, 0, -1, 1};
int graph[LIMIT][LIMIT];
int dp[LIMIT][LIMIT];
int m, n;

int DFS(int y, int x){
	if(y == m && x == n) return 1;
	if(dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 1 || nx < 1 || ny > m || nx > n) continue;
		if(graph[ny][nx] >= graph[y][x]) continue;
		dp[y][x] += DFS(ny, nx);
	}
	return dp[y][x];
	
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m >> n;
	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin >> graph[i][j];

	cout << DFS(1, 1);
}