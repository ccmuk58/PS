#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
constexpr int N_LIMIT = 1002;
constexpr int B_LIMIT = 11;
constexpr int T_LIMIT = 2;

struct Block {
	int y;
	int x;
	int cnt;
	int brk;
	bool time;
};
int N, M, K;
int map[N_LIMIT][N_LIMIT];
bool visited[N_LIMIT][N_LIMIT][B_LIMIT][T_LIMIT];
int dy[] = { 0,0,-1,+1 };
int dx[] = { -1,+1,0,0 };
int ans;

void BFS() {
	queue<Block> q;
	q.push({ 1,1,1,K,true});
	visited[1][1][K][true] = true;

	while (!q.empty())
	{
		auto [y, x, cnt, brk, time] = q.front();
		q.pop();

		if (y == N && x == M)
		{
			ans = cnt;
			return;
		}

		cnt++;
		time = !time;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ry, rx, rb;
			if (map[ny][nx])
			{
				if (brk <= 0) continue;
				if (!time)
				{
					ry = ny;
					rx = nx;
					rb = brk - 1;
				}
				else
				{
					ry = y;
					rx = x;
					rb = brk;
				}
			}
			else
			{
				ry = ny;
				rx = nx;
				rb = brk;
			}
			if (ry<1 || ry>N || rx<1 || rx>M) continue;
			if (visited[ry][rx][rb][time]) continue;
			visited[ry][rx][rb][time] = true;
			q.push({ ry, rx, cnt, rb, time });

		}
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