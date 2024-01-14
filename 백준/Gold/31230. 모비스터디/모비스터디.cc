#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 200001;
vector<pl> v[LIMIT];
int n, m, a, b;
ll dist[LIMIT];
priority_queue<pl, vector<pl>, greater<pl>> pq;
vector<int> path[LIMIT];
set<int> pathSet;

void pathFunc(int cur)
{
	if(cur == a)
		return;
	for(int i=0; i<path[cur].size(); i++)
	{
		pathSet.insert(path[cur][i]);
		pathFunc(path[cur][i]);
	}
}
void djkstra()
{
	pq.push({0, a});
	dist[a] = 0;
	path[a].push_back(a);
	while(!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();

		if(dist[cur] < cost)
			continue;
		if(cur == b)
		{
			pathFunc(cur);
			continue;
		}

		for(int i=0; i<v[cur].size(); i++)
		{
			auto [nCost, next] = v[cur][i];
			if(dist[next] > dist[cur] + nCost)
			{
				dist[next] = dist[cur] + nCost;
				path[next].clear();
				path[next].push_back(cur);
				pq.push({dist[next], next});
			}
			else if(dist[next] == dist[cur] + nCost)
			{
				path[next].push_back(cur);
			}
		}
		
	}

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m >> a >> b;
	// djkstra
	for(int i=1; i<=m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		v[s].push_back({c, e});
		v[e].push_back({c, s});
	}
	fill(dist, dist+LIMIT, 1e18);
	pathSet.insert(a);
	pathSet.insert(b);
	djkstra();

	cout << pathSet.size() << "\n";
	for(auto i : pathSet)
		cout << i << " ";
}