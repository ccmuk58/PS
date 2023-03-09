#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
constexpr int VLIMIT = 20002;
constexpr int MAX = 2123456789;

struct Info{
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
int V, E, K;
vector<Info> graph[VLIMIT];
int dis[VLIMIT];
bool visited[VLIMIT];
void Dijkstra(int start)
{
	for(auto &d : dis)
		d = MAX;

	priority_queue<Info,vector<Info>, cmp> pq;
	pq.push({start, 0});
	dis[start] = 0;
	visited[start] = true;

	while(!pq.empty())
	{
		int node = pq.top().node;
		int sum = pq.top().cost;
		visited[node] = true;
		pq.pop();


		for(int i=0; i<graph[node].size(); i++)
		{
			auto next = graph[node][i];
			if(visited[next.node]) continue;
			int nSum = sum + next.cost;
			if(dis[next.node] <= nSum) continue;
			dis[next.node] = nSum;
			pq.push({next.node, nSum});
		}
	}

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> V >> E >> K;

	int u, v, w;
	for(int i=0; i<E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}

	Dijkstra(K);
	for(int i=1; i<=V; i++)
	{
		if(dis[i]==MAX) cout << "INF\n";
		else cout << dis[i] << "\n";
	}
}