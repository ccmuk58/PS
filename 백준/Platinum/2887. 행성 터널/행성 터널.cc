#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 100001;
using pInt = pair<int, int>;
using ll = long long;
vector<pInt> X, Y, Z;
vector<pInt> graph[LIMIT];
bool visited[LIMIT];
int N;
ll result;
int vCnt;
void prim()
{
	priority_queue<pInt, vector<pInt>, greater<pInt>> pq;
	for (int i = 0; i < graph[0].size(); i++)
	{
		pq.push(graph[0][i]);
	}
	visited[0] = true;
	vCnt++;

	while (vCnt < N)
	{
		auto [cost, idx] = pq.top();
		pq.pop();
		if (visited[idx]) continue;
		visited[idx] = true;
		vCnt++;
		result += (ll)cost;
		for (int i = 0; i < graph[idx].size(); i++)
		{
			auto [nCost, nIdx] = graph[idx][i];
			if (visited[graph[idx][i].second]) continue;
			pq.push({ nCost, nIdx });
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N - 1; i++)
	{
		graph[X[i].second].push_back({ X[i + 1].first - X[i].first, X[i + 1].second });
		graph[X[i + 1].second].push_back({ X[i + 1].first - X[i].first, X[i].second });

		graph[Y[i].second].push_back({ Y[i + 1].first - Y[i].first, Y[i + 1].second });
		graph[Y[i + 1].second].push_back({ Y[i + 1].first - Y[i].first, Y[i].second });

		graph[Z[i].second].push_back({ Z[i + 1].first - Z[i].first, Z[i + 1].second });
		graph[Z[i + 1].second].push_back({ Z[i + 1].first - Z[i].first, Z[i].second });
	}
	prim();

	cout << result;
}