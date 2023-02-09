#include<iostream>
#include<vector>
using namespace std;
constexpr int LIMIT = 502;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };

int n;
int block[LIMIT][LIMIT];
int dp[LIMIT][LIMIT];
int ans;

int DFS(int y, int x)
{
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		// if (ny < 0 || nx < 0 || ny == n || nx == n) continue;
		if (block[ny][nx] <= block[y][x]) continue;
		dp[y][x] = max(dp[y][x], DFS(ny, nx) + 1);
	}
	return dp[y][x];
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			cin >> block[j][k];

	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			ans = max(ans, DFS(j, k));

	cout << ans;
}