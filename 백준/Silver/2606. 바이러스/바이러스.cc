#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
constexpr int RANGE = 102;

int bfs(vector<int>* g, int start) {
	int visited[RANGE]{};
	int cnt = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int nowV = q.front();
		q.pop();

		if (visited[nowV]) continue;
		visited[nowV] = true;
		cnt++;

		for (int i = 0; i < g[nowV].size(); i++)
			q.push(g[nowV][i]);
	}
	return cnt-1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	vector<int> graph[RANGE]{};

	cin >> v >> e;

	for (int i = 1; i <= e; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	int cnt = bfs(graph, 1);
	cout << cnt;
}