#include <bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 300 + 2;
using pi = pair<int, int>;

vector<int> w;
vector<pi> graph[LIMIT];
bool visited[LIMIT];
int waterCnt;
int result;
int n;

void Prim(){
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	for(int i=0; i<n; i++)
		pq.push({w[i], i});
	
	while(waterCnt < n)
	{
		auto [cost, idx] = pq.top();
		pq.pop();

		if(visited[idx]) continue;
		visited[idx] = true;
		result+=cost;
		waterCnt++;

		for(auto& next : graph[idx])
		{
			if(visited[next.second]) continue;
			pq.push(next);
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> n;

	for(int i=0; i<n; i++) 
	{
		int cost;
		cin >> cost;
		w.push_back(cost);
	}

	for(int i=0; i<n; i++) 
	{
		for(int j=0; j<n; j++) 
		{
			int cost;
			cin >> cost;
			if(i == j) continue;
			graph[i].push_back({cost, j});
			graph[j].push_back({cost, i});
		}
	}

	Prim();

	cout << result;
}