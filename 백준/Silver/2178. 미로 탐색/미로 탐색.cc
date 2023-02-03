#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
constexpr int LIMIT = 102;

struct Block
{
	int y;
	int x;
	int count;
};

int maze[LIMIT][LIMIT]{};
int visited[LIMIT][LIMIT]{};
int N, M;

int bfs() {
	queue<Block> q;
	q.push({ 1,1,1 });
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().count;
		q.pop();

		if (!maze[y][x] || visited[y][x]) continue;
		if (y == N && x == M) return cnt;
		visited[y][x] = true;

		cnt++;
		q.push({ y - 1 , x, cnt });
		q.push({ y + 1, x, cnt });
		q.push({ y , x - 1, cnt });
		q.push({ y , x + 1, cnt });
	}
	return 0;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	cout << bfs();
}