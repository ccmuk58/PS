#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int LIMIT = 30;

int house[LIMIT][LIMIT]{};
bool visited[LIMIT][LIMIT]{};
int ans;
bool isFirst;
vector<int> cnt;

void dfs(int y, int x)
{
	if (visited[y][x] || !house[y][x]) return;
	if (isFirst)
	{
		ans++;
		cnt.push_back(0);
	}
	isFirst = false;
	visited[y][x] = true;
	cnt.back()++;

	dfs(y, x - 1);
	dfs(y, x + 1);
	dfs(y - 1, x);
	dfs(y + 1, x);
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &house[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			isFirst = true;
			dfs(i, j);
		}
	}

	sort(cnt.begin(), cnt.end());
	vector<int>::iterator iter;
	cout << ans << "\n";
	for (iter = cnt.begin(); iter != cnt.end(); iter++)
		cout << *iter << "\n";
}