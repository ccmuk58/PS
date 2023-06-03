#include<bits/stdc++.h>
using namespace std;
using pInt = pair<int, int>;
constexpr int LIMIT = 1001;
int V, E;
bool visited[LIMIT];
vector<pInt> graph[LIMIT];
int gender[LIMIT];
int cnt;
int result;
void prim()
{
	priority_queue<pInt, vector<pInt>, greater<pInt>> pq;

	for (int i = 0; i < graph[1].size(); i++)
	{
		auto [nDist, nIdx] = graph[1][i];
		pq.push({ nDist, nIdx });
	}
	visited[1] = true;
	cnt++;
	while (cnt < V)
	{
		if (pq.empty())
		{
			result = -1;
			return;
		}
		auto [dist, idx] = pq.top();
		pq.pop();

		if (visited[idx]) continue;
		visited[idx] = true;
		cnt++;
		result += dist;

		for (int i = 0; i < graph[idx].size(); i++)
		{
			auto [nDist, nIdx] = graph[idx][i];
			if (visited[nIdx]) continue;
			pq.push({ nDist, nIdx });
		}
	}

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> E;
	int A, B, C;
	for (int i = 1; i <= V; i++)
	{
		char c;
		cin >> c;
		if (c == 'W') gender[i] = 1;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		if (gender[A] == gender[B]) continue;
		graph[A].push_back({ C, B });
		graph[B].push_back({ C, A });
	}
	prim();
	cout << result;
}