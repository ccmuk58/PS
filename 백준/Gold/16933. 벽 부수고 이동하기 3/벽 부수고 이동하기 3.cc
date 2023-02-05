#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
constexpr int N_LIMIT = 1002;
constexpr int B_LIMIT = 12;
constexpr int M_LIMIT = 3;

struct Block {
	int y;
	int x;
	int cnt;
	int brk;
	int time;
	int moveType;
};
int N, M, K;
int map[N_LIMIT][N_LIMIT];
int visited[N_LIMIT][N_LIMIT][B_LIMIT][M_LIMIT];
int dy[] = { 0,0,-1,+1, 0 };
int dx[] = { -1,+1,0,0, 0 };
int ans;

void BFS() {
	queue<Block> q;
	q.push({ 1,1,0,K,-1, 0});

	while (!q.empty())
	{
		auto [y, x, cnt, brk, time, move] = q.front();
		cnt++;
		time *= -1;
		q.pop();

		if (y<1 || y>N || x<1 || x>M) continue;
		if (visited[y][x][brk][move]) continue;
		visited[y][x][brk][move] = 1;
		if (map[y][x] && move)
		{
			if (brk <= 0) continue;
			brk--;
			if (time >= 0) 
			{
				q.push({ y , x , cnt, brk, time, 0 });
				continue;
			}
		}
		if (y == N && x == M)
		{
			ans = cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
			q.push({ y + dy[i], x + dx[i], cnt, brk, time, 1});
	}
	ans = -1;
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);

	BFS();
	cout << ans;
}