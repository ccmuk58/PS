#include<iostream>
#include<queue>
using namespace std;
constexpr int LIMIT = 1002;

struct Block {
	int y;
	int x;
	int cnt;
	int brk;
};
int N, M;
int map[LIMIT][LIMIT];
int visited[LIMIT][LIMIT][2];
int dy[] = { 0,0,-1,+1 };
int dx[] = { -1,+1,0,0 };
int ans;

void BFS() {
	queue<Block> q;
	q.push({ 1,1,0,1 });

	while (!q.empty())
	{
		auto [y, x, cnt, brk] = q.front();
		cnt++;
		q.pop();

		if (y<1 || y>N || x<1 || x>M) continue;
		if (visited[y][x][brk]) continue;
		visited[y][x][brk] = 1;
		if (map[y][x] && brk == 0) continue;
		if (map[y][x] && brk > 0) brk--;
		if (y == N && x == M)
		{
			ans = cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
			q.push({ y + dy[i], x + dx[i], cnt, brk });
	}
	ans = -1;
}


int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);

	BFS();
	cout << ans;
}
