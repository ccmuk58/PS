#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 9;
constexpr int dy[4] = { 0,0,-1,1 };
constexpr int dx[4] = { -1,1,0,0 };
using pInt = pair<int, int>;
int N, M;
int result;
int graph[LIMIT][LIMIT];
int bfsGraph[LIMIT][LIMIT];
void bfs()
{
	queue<pInt> q;

	bool isFInd = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			bfsGraph[i][j] = graph[i][j];
			if (bfsGraph[i][j] == 2)
				q.push({ i, j });
		}
	}

	while (!q.empty())
	{
		auto& [y, x] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (bfsGraph[ny][nx])continue;
			bfsGraph[ny][nx] = 2;
			q.push({ ny, nx });
		}
	}

	int safe = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (bfsGraph[i][j] == 0) safe++;

	result = max(result, safe);
}
void setWall(int idx) {
	if (idx == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j]) continue;
			graph[i][j] = 1;
			setWall(idx + 1);
			graph[i][j] = 0;
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];

	setWall(0);
	cout << result;
}