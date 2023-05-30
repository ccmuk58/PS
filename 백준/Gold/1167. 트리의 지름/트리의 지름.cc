#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 100001;

struct Node {
	int idx;
	int cost;
	int sum = 0;
};

vector<Node> graph[LIMIT];

Node dfs(int startIdx)
{
	bool visited[LIMIT]{};
	stack<Node> s;
	vector<Node> startVector = graph[startIdx];
	visited[startIdx] = true;
	for (int i = 0; i < startVector.size(); i++)
	{
		s.push(startVector[i]);
		visited[startVector[i].idx] = true;
	}
	Node maxNode;

	while (!s.empty())
	{
		auto [idx,cost,sum] = s.top();
		sum += cost;
		if (sum > maxNode.sum) maxNode = {idx, cost, sum};
		s.pop();
		for (int i = 0; i < graph[idx].size(); i++)
		{
			Node nextNode = graph[idx][i];
			if (visited[nextNode.idx]) continue;
			visited[nextNode.idx] = true;
			nextNode.sum = sum;
			s.push(nextNode);
		}
	}
	return maxNode;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int V;
	int curV = 0;
	int nextV, edge;
	cin >> V;
	for (int i = 0; i < V; i++)
	{
		cin >> curV;
		while (true)
		{
			cin >> nextV;
			if (nextV == -1) break;
			cin >> edge;
			graph[curV].push_back({ nextV,edge});
			graph[nextV].push_back({ curV,edge });
		}
	}

	Node startNode = dfs(1);
	Node endNode = dfs(startNode.idx);
	cout << endNode.sum;
}