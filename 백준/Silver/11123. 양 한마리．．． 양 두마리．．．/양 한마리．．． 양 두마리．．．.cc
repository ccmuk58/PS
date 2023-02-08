#include<iostream>
#include<cstring>
using namespace std;
constexpr int LIMIT = 102;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };

int T, H, W;
char sheep[LIMIT][LIMIT];
bool visited[LIMIT][LIMIT];
int ans;

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny == H || ny < 0 || nx == W || nx < 0) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = true;
		if (sheep[ny][nx] != '#') continue;
		DFS(ny, nx);
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> H >> W;
		for (int j = 0; j < H; j++)
			for (int k = 0; k < W; k++)
				cin >> sheep[j][k];

		for (int j = 0; j < H; j++)
		{
			for (int k = 0; k < W; k++)
			{
				if (sheep[j][k] != '#' || visited[j][k]) continue;
				DFS(j, k);
				ans++;
			}
		}
		cout << ans << "\n";
		ans = 0;
		memset(visited, false, LIMIT * LIMIT * sizeof(bool));
	}
}