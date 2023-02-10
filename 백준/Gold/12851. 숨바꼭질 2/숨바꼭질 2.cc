#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
constexpr int LIMIT = 100000;

struct Info
{
	int x;
	int cnt;
};
int N, K;
int visited[LIMIT + 2];
int ans = LIMIT + 2;
int ansCnt;

void BFS()
{
	queue<Info> q;
	q.push({ N, 0 });

	while (!q.empty())
	{
		auto [x, cnt] = q.front();
		q.pop();

		if (ans < cnt) continue;
		if (x < 0 || x > LIMIT) continue;
		if (x == K)
		{
			ansCnt++;
			ans = cnt;
		}

		if (visited[x] < cnt) continue;
		visited[x] = cnt;
		q.push({ x - 1, cnt + 1 });
		q.push({ x + 1, cnt + 1 });
		q.push({ x * 2 , cnt + 1 });
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;

	for (auto& v : visited)
		v = LIMIT + 2;

	BFS();

	cout << ans << "\n" << ansCnt;
}