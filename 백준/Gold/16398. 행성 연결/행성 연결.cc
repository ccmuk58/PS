#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e3 + 2;
vector<pl> graph[LIMIT];
bool visited[LIMIT];
int edgeCnt;
ll result;
int n;

void Prim() {
    priority_queue<pl, vector<pl>, greater<pl>> pq;

    for (int i = 0; i < graph[1].size(); i++)
	{
		pq.push(graph[1][i]);
	}
	visited[1] = true;

	while(edgeCnt < n-1)
	{
		auto [cost, node] = pq.top();
		pq.pop();

		if (visited[node]) continue;
		visited[node] = true;
		result += cost;
		edgeCnt++;

		for(int i=0; i<graph[node].size(); i++)
		{
			auto [nCost, nNode] = graph[node][i];
			if (visited[nNode]) continue;

			pq.push({ nCost, nNode });
		}
		
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;
			if(!cost) continue;
			graph[i].push_back({ cost, j });
        }
    }

	Prim();
	cout << result;
}