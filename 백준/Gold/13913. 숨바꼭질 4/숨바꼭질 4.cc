#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
constexpr int LIMIT = 100000;
constexpr int dx[] = { -1, 1, 2 };

struct Info
{
	int x;
	int cnt;
};
int N, K;
int parent[LIMIT + 2];
int ans;
stack<int> path;

void BFS()
{
	queue<Info> q;
	q.push({ N, 0 });
	parent[N] = -2;

	while (!q.empty())
	{
		auto [x, cnt] = q.front();
		q.pop();

		if (x == K)
		{
			ans = cnt;

			int p = x;
			while (p != -2){
				path.push(p);
				p = parent[p];
			}
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx;
			if (i < 2) nx = x + dx[i];
			else  nx = x * dx[i];

			if (nx < 0 || nx > LIMIT) continue;
			if (parent[nx] != -1) continue;
			parent[nx] = x;

			q.push({ nx, cnt + 1 });
		}
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;

	memset(parent, -1, (LIMIT + 2) * sizeof(int));
	BFS();

	cout << ans << "\n";
	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}
}