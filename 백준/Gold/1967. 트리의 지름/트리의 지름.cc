#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 10001;
struct Node {
	int idx;
	int dist;
};
int n;
vector<Node> graph[LIMIT];
bool visited[LIMIT];
int maxDistIdx = 1;
int maxDist;
void dfs(int idx, int distSum = 0) {
	if (distSum > maxDist)
	{
		maxDist = distSum;
		maxDistIdx = idx;
	}
	for (int i = 0; i < graph[idx].size(); i++)
	{
		auto& [nIdx, dist] = graph[idx][i];
		if (visited[nIdx]) continue;
		visited[nIdx] = true;
		dfs(nIdx, distSum + dist);
	}
}
	
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	int from, to, dist;
	for (int i = 0; i < n-1; i++)
	{
		cin >> from >> to >> dist;
		graph[from].push_back({ to, dist });
		graph[to].push_back({ from, dist });
	}

	for (int i = 0; i < 2; i++)
	{
		memset(visited, 0, sizeof(visited));
		visited[maxDistIdx] = true;
		dfs(maxDistIdx);
	}
	cout << maxDist;
}