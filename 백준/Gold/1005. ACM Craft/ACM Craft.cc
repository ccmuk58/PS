#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int cost[n+1] = {};
        int indegree[n+1] = {};
		int dp[n+1] = {};
		vector<int> v[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
        }
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			indegree[b]++;
		}

        int w;
        cin >> w;
        queue<int> q;
        for (int i = 1; i <= n; i++)
		{
            if (indegree[i] == 0) {
				q.push(i);
				dp[i] = cost[i];
			}
		}

        while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for(int j = 0; j < v[cur].size(); j++)
			{
				int next = v[cur][j];
				dp[next] = max(dp[next], dp[cur] + cost[next]);
				indegree[next]--;
				if (indegree[next] == 0)
					q.push(next);
			}
        }
		cout << dp[w] << '\n';
    }
}