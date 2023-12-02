#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
constexpr int MAX = 2000 + 1;
constexpr int INF = 1e9 + 1;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	vector<int> graph[n+1];
	int inDegree[n+1] ={};
	vector<int> ans;
	for(int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		int a, b;
		cin >> a;
		for(int j = 1; j < t; j++)
		{
			cin >> b;
			graph[a].push_back(b);
			inDegree[b]++;
			a = b;
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(inDegree[i] == 0)
			q.push(i);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for(int i=0; i<graph[cur].size(); i++){
			int next = graph[cur][i];
			inDegree[next]--;
			if(inDegree[next] == 0)
				q.push(next);
		}
	}

	if(ans.size() != n)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}