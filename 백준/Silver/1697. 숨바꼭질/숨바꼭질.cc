#include<iostream>
#include<queue>
using namespace std;
constexpr int LIMIT = 100000;

struct Info
{
	int x;
	int cnt;
};
int N, K;
bool visited[LIMIT + 2];
int ans;

void BFS()
{
	queue<Info> q;
	q.push({ N, 0 });

	while (!q.empty())
	{
		auto [x, cnt] = q.front();
		q.pop();

		if (x == K)
		{
			ans = cnt;
			return;
		}

		if (x < 0 || x > LIMIT) continue;
		if (visited[x]) continue;
		visited[x] = true;
		cnt++;
		q.push({ x - 1, cnt });
		q.push({ x + 1, cnt });
		q.push({ x * 2 , cnt });
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;

	BFS();

	cout << ans;
}