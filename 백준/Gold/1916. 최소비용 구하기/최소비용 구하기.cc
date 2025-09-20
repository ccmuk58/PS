#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	vector<pi> v[N+2];
	int cost[N+2]={};
	fill(cost, cost+N+1, INT32_MAX);

	for(int i=0; i<M; i++)
	{
		cin >> A >> B >> C;
		v[A].push_back({C, B});
	}

	int st=0;
	int ed=0;
	cin >> st >> ed;

	priority_queue<pi> pq;
	pq.push({0, st});
	while(!pq.empty())
	{
		auto [cs, n] = pq.top();
		cs*=-1;
		pq.pop();

		if(n==ed) break;
		for(int i=0; i<v[n].size(); i++)
		{
			int nc = v[n][i].first;
			int nn = v[n][i].second;
			if(cost[nn] <= cs + nc) continue;

			cost[nn] = cs + nc;
			pq.push({-cost[nn], nn});
		}
	}

	cout << cost[ed];
}