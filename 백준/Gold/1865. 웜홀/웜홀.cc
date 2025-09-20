#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = INT64_MAX/10;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> T;

	while(T--)
	{
		cin >> N >> M >> W;

		vector<pll> edge;
		for(int i=0; i<M; i++)
		{
			cin >> A >> B >> C;
			edge.push_back({C,{A,B}});
			edge.push_back({C,{B,A}});
		}
		
		for(int i=0; i<W; i++)
		{
			cin >> A >> B >> C;
			edge.push_back({-C,{A,B}});
		}

		bool isYes = false;
		ll cost[N+2] = {};
		fill(cost, cost+N+2, LMT);
		cost[1] = 0;

		for(int j=1; j<=N-1; j++)
		{
			for(int i=0; i<edge.size(); i++)
			{
				auto c = edge[i].first;
				auto u = edge[i].second.first;
				auto v = edge[i].second.second;
	
				cost[v] = min(cost[v], c+cost[u]);
			}
		}
		for(int i=0; i<edge.size(); i++)
		{
			auto c = edge[i].first;
			auto u = edge[i].second.first;
			auto v = edge[i].second.second;

			if(cost[v] > cost[u]+c)
			{
				isYes = true;
				break;
			}
		}
	
		cout << ((isYes)? "YES\n":"NO\n");
	}

}