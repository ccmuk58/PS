#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
constexpr int LIMIT = 102;

struct Block{
	int y;
	int x;
	int cnt;
};
int map[LIMIT][LIMIT]{};
int tags[LIMIT][LIMIT]{};
int tag;
int ans = 10000;
int N;

void DFS(int y, int x)
{

	if (!map[y][x] || tags[y][x]) return;
	tags[y][x] = tag;

	DFS(y, x-1);
	DFS(y, x+1);
	DFS(y-1, x);
	DFS(y+1, x);
}
void BFS(int y, int x)
{
	bool visited[LIMIT][LIMIT]{};
	int startTag = tags[y][x];

	queue<Block> q;
	q.push({ y, x, 1 });

	while (!q.empty())
	{
		int qy = q.front().y;
		int qx = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		//  OutOfBounds 방지
		if (qy < 1 || qx < 1 || qy > N || qx > N) continue;

		// 메모리 초과 방지
		if (visited[qy][qx]) continue;
		visited[qy][qx] = true;
		
		int nowTag = tags[qy][qx];
		
		// 시간 초과 방지
		if (nowTag == startTag && (y != qy && x != qx)) continue;

		// 최단 경로 체크
		if (nowTag && nowTag != startTag)
		{
			ans = ans > cnt ? cnt : ans;
			return;
		}
		cnt++;
		q.push({ qy, qx-1, cnt });
		q.push({ qy, qx+1, cnt });
		q.push({ qy-1, qx, cnt });
		q.push({ qy+1, qx, cnt });
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
			tag++;
			DFS(i, j);
		}
	}
	
	// 최단 경로 다리 찾기(BFS)
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!tags[i][j]) continue;
			BFS(i, j);
		}
	}
	ans -= 2;
	cout << ans;
}