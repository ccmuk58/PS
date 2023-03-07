#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
constexpr int LIMIT = 1002;
constexpr int MAX = 2123456789;
struct Info{
	int node;
	int cost;
};
struct cmp{
	bool operator()(Info &l, Info &r){
		return l.cost>r.cost;
	}
};

vector<Info> graph[LIMIT];
int N, M, X;
int ans;


int Dijkstra(int start, int end)
{
	priority_queue<Info, vector<Info>, cmp> pq;
	int distance[N+1];
	bool visited[N+1]{};
	for(auto &d : distance)
		d = MAX;
	visited[start] = true;

	pq.push({start, 0});

	while(!pq.empty())
	{
		auto [cur, sum] = pq.top();
		visited[cur] = true;
		pq.pop();

		if(cur == end)
		{
			if(end == X && start != end)
			{
				sum += Dijkstra(end, start);
				if(ans < sum) ans = sum;
			} 
			return sum;
		}

		for(int i=0; i<graph[cur].size(); i++)
		{
			Info next = graph[cur][i];
			if(visited[next.node]) continue;
			int nSum = sum + next.cost;
			if(distance[next.node] < nSum) continue;
			pq.push({next.node, nSum});
		}
	}

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> X;
	int s,e,t;
	for(int i=0; i<M; i++)
	{
		cin >> s >> e >> t;
		graph[s].push_back({e,t});
	}

	for(int i=1; i<=N; i++)
	{
		int cost = Dijkstra(i,X);
		if(ans < cost) ans = cost;
	}

	cout << ans;
}