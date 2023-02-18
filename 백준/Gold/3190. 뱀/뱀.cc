#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
constexpr int LIMIT = 102;
constexpr int dy[] = { 0,1,0,-1 };
constexpr int dx[] = { 1,0,-1,0 };

int N, K, L;
int board[LIMIT][LIMIT];
int turn[LIMIT * LIMIT];
int dir;
queue<pair<int, int>> snakeQ;

int solution()
{
	int time = 0;
	int ny = 1;
	int nx = 1;
	snakeQ.push({ ny,nx });
	while (!snakeQ.empty())
	{
		dir += turn[time];
		if (dir < 0) dir = 3;
		if (dir > 3) dir = 0;

		ny += dy[dir];
		nx += dx[dir];
		time++;

		queue<pair<int, int>> q = snakeQ;
		while (!q.empty())
		{
			if (q.front().first == ny && q.front().second == nx)
				return time;
			q.pop();
		}
		if (ny == 0 || nx == 0 || ny > N || nx > N)
			return time;

		snakeQ.push({ ny, nx });
		if (board[ny][nx]) board[ny][nx] = 0;
		else snakeQ.pop();
	}
	return time;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	int ay;
	int ax;
	for (int i = 0; i < K; i++)
	{
		cin >> ay >> ax;
		board[ay][ax] = 1;
	}
	cin >> L;
	int X;
	char C;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		if (C == 'L') turn[X] = -1;
		else turn[X] = 1;
	}

	int ans = solution();
	cout << ans;
}