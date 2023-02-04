#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 102;

struct Box
{
	int z;
	int y;
	int x;
	int cnt;
};
int M, N, H;
int tmt[LIMIT][LIMIT][LIMIT];
int dz[] = { 0,0,0,0,-1,1 };
int dy[] = { 0,0,-1,1,0,0 };
int dx[] = { -1,1,0,0,0,0 };
int ans;

void BFS()
{
	queue<Box> q;
	for (int k = 1; k <= H; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (tmt[k][i][j] == 1) q.push({ k ,i, j, 0 });
			}
		}
	}
	int firstSize = q.size();

	while (!q.empty())
	{
		int qz = q.front().z;
		int qy = q.front().y;
		int qx = q.front().x;
		int qc = q.front().cnt;
		q.pop();

		if (qz < 1 || qz > H || qy < 1 || qy > N || qx < 1 || qx > M) continue;

		if (tmt[qz][qy][qx] && firstSize-- < 1) continue;
		tmt[qz][qy][qx] = 1;

		ans = qc++;
		for (int i = 0; i < 6; i++)
		{
			int z = qz + dz[i];
			int y = qy + dy[i];
			int x = qx + dx[i];
			q.push({ z,y,x,qc });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;

	for (int k = 1; k <= H; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> tmt[k][i][j];
			}
		}
	}

	BFS();

	for (int k = 1; k <= H; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (!tmt[k][i][j]) ans = -1;
			}
		}
	}
	cout << ans;
}