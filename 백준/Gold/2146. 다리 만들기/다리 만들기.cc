#include<iostream>
#include<queue>
using namespace std;
constexpr int LIMIT = 102;
constexpr int MAX = 100000;

struct Block{
	int y;
	int x;
	int dis;
};
int dy[] = { 0,0,1,-1 };
int dx[] = { -1,1,0,0 };
int map[LIMIT][LIMIT]{};
int names[LIMIT][LIMIT]{};
int cnt;
int ans = MAX;
int N;

void DFS(int y, int x)
{
	if (!map[y][x] || names[y][x]) return;
	names[y][x] = cnt;
	
	for (int i = 0; i < 4; i++)
		DFS(y + dy[i], x + dx[i]);
}
void BFS(int y, int x)
{
	bool visited[LIMIT][LIMIT]{};
	int sIsland = names[y][x];

	queue<Block> q;
	q.push({ y, x, 0 });

	while (!q.empty())
	{
		int qy = q.front().y;
		int qx = q.front().x;
		int dis = q.front().dis + 1;
		int nIsland = names[qy][qx];
		q.pop();

		//  OutOfBounds 방지
		if (qy < 1 || qx < 1 || qy > N || qx > N) continue;

		// 메모리 초과 방지
		if (visited[qy][qx]) continue;
		visited[qy][qx] = true;
		
		// 시간 초과 방지 (같은 섬간 이동 제한)
		if (nIsland == sIsland && (y != qy && x != qx)) continue;

		// 최단 경로 체크
		if (nIsland && nIsland != sIsland)
		{
			ans = ans > dis ? dis : ans;
			return;
		}

		for (int i = 0; i < 4; i++)
			q.push({ qy + dy[i], qx + dx[i], dis });
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	// 섬 구하기(DFS)
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!map[i][j]) continue;
			cnt++;
			DFS(i, j);
		}
	}
	
	// 최단 경로 다리 찾기(BFS)
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!map[i][j]) continue;
			BFS(i, j);
		}
	}
	ans -= 2;
	cout << ans;
}
