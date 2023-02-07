#include<iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 10;

int N, M;
int num[LIMIT];
bool visited[LIMIT];

void DFS(int cnt)
{
	if (cnt > M)
	{
		for (int i = 1; i <= M; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		num[cnt] = i;
		DFS(cnt+1);
		visited[i] = false;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	// N까지 수를 M개 고른 수열
	cin >> N >> M;
	DFS(1);
}