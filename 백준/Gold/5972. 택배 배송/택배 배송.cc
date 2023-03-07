#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
constexpr int LIMIT = 50002;
constexpr int MAX = 2123456789;
struct Info
{
	int node;
	int cost;
};
struct cmp 
{
	bool operator()(const Info &l, const Info &r) const 
	{
		return l.cost > r.cost;
	}
};

vector<Info> graph[LIMIT];
int dis[LIMIT];
bool fin[LIMIT];
int N, M;

void Dijkstra()
{
	priority_queue<Info, vector<Info>, cmp> pq;
	pq.push({ 1, 0 });
	fin[1] = true;
	while (!pq.empty())
	{
		auto [cur, sum] = pq.top();
		if (cur == N) break;
		fin[cur] = true;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			auto next = graph[cur][i];
			if (fin[next.node]) continue;
			int nSum = sum + next.cost;
			if (dis[next.node] <= nSum) continue;
			dis[next.node] = nSum;

			pq.push({ next.node, nSum });
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		dis[i] = MAX;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	Dijkstra();
	
	cout << dis[N];
}