#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
constexpr int RANGE = 102;

bool fam[RANGE][RANGE]{};
bool visited[RANGE]{};
int from, to;
int n, m;
int ans = -1;

void dfs(int v, int cnt) {
	if (v == to) {
		ans = cnt;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (fam[v][i] && !visited[i])
		{
			visited[i] = true;
			dfs(i, cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> from >> to >> m;
	int x, y;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		fam[y][x] = fam[x][y] = true;
	}
	dfs(from, 0);
	cout << ans;
}