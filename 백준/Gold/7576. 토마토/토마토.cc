#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 1002;

struct Box
{
	int y;
	int x;
	int cnt;
};
int M, N;
int tmt[LIMIT][LIMIT];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
int ans;

void BFS()
{
	queue<Box> q;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (tmt[i][j] == 1) q.push({ i, j, 0 });
		}
	}
	int firstSize = q.size();


	while (!q.empty())
	{
		int qy = q.front().y;
		int qx = q.front().x;
		int qc = q.front().cnt;
		q.pop();

		if (qy < 1 || qy > N || qx < 1 || qx > M) continue;
		if (tmt[qy][qx] && firstSize-- < 1) continue;
		tmt[qy][qx] = 1;

		ans = qc++;
		for (int i = 0; i < 4; i++)
		{
			int y = qy + dy[i];
			int x = qx + dx[i];
			q.push({ y,x,qc });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> tmt[i][j];
		}
	}

	BFS();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!tmt[i][j]) ans = -1;
		}
	}
	cout << ans;
}