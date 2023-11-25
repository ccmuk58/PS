#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pi = pair<int, int>;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<vector<int>> v(n + 1);
    int indegree[n + 1] = {};
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			indegree[next]--;
			if(indegree[next] == 0) pq.push(next);
        }
    }
}