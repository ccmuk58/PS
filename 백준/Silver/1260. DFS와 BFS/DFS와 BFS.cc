#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int N, M, V;
vector<int> graph[1002];

void dfs() 
{
	bool visit[1002]{};
	stack<int> s;
	s.push(V);


	for (int i = 1; i <= N; i++)
		sort(graph[i].rbegin(), graph[i].rend());

	while (!s.empty())
	{
		int v = s.top();
		s.pop();
		if (visit[v]) continue;
		
		visit[v] = true;
		cout << v << " ";

		for (int i = 0; i < graph[v].size(); i++) {
			if (visit[graph[v][i]]) continue;
			s.push(graph[v][i]);
		}
	}
	cout << "\n";
}
void bfs()
{
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	bool visit[1002]{};
	queue<int> q;
	q.push(V);


	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (visit[v]) continue;

		visit[v] = true;
		cout << v << " ";

		for (int i = 0; i < graph[v].size(); i++) {
			if (visit[graph[v][i]]) continue;
			q.push(graph[v][i]);
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs();
	bfs();
}