#include<bits/stdc++.h>
using namespace std;
using pInt = pair<int, int>;
using pDI = pair<double, int>;
constexpr int LIMIT = 101;
int n;
bool visited[LIMIT];
pInt pos[LIMIT];
vector<pDI> graph[LIMIT];
int cnt;
float result;

void prim()
{
	priority_queue<pDI, vector<pDI>, greater<pDI>> pq;

	for (int i = 0; i < graph[1].size(); i++)
	{
		auto [nDist, nIdx] = graph[1][i];
		pq.push({ nDist, nIdx });
	}
	visited[1] = true;
	cnt++;
	while (cnt < n)
	{
		auto [dist, idx] = pq.top();
		pq.pop();

		if (visited[idx]) continue;
		visited[idx] = true;
		cnt++;
		result += dist;

		for (int i = 0; i < graph[idx].size(); i++)
		{
			auto [nDist, nIdx] = graph[idx][i];
			if (visited[nIdx]) continue;
			pq.push({ nDist, nIdx });
		}
	}
}
double getDistance(pInt a, pInt b)
{
	return sqrt(pow(b.first- a.first, 2) + pow(b.second - a.second, 2));
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	float x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		pos[i] = make_pair(x, y);
		for (int j = 0; j < i; j++)
		{
			graph[i].push_back({ getDistance(pos[i], pos[j]), j });
			graph[j].push_back({ getDistance(pos[i], pos[j]), i });
		}
	}
	prim();
	cout << result;
}