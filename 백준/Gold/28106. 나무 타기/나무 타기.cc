#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int MOD = 1e9 + 7;
constexpr int LMT = 2e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll dp[LMT] = {};
vector<int> g[LMT];
ll power[LMT] = {};
ll ans = 0;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	int st=0;
	for(int i=1; i<=N; i++)
	{
		cin >> A;
		if(A==0) st=i;
		g[A].push_back(i);
	}

	for(int i=1; i<=N; i++)
	{
		cin >> A;
		power[i] = A;
	}

	queue<int> stq;
	vector<int> stv;
	stq.push(st);
	stv.push_back(st);

	while(!stq.empty())
	{
		auto cur = stq.front();
		stq.pop();

		for(int i=0; i<g[cur].size(); i++)
		{
			stq.push(g[cur][i]);
			stv.push_back(g[cur][i]);
		}
	}
	dp[st] = 1;

	for(int i=0; i<stv.size(); i++)
	{
		queue<pi> q;
		int s = stv[i];
		q.push({s, power[s]});
		while(!q.empty())
		{
			auto cur = q.front();
			q.pop();
			if(cur.second == 0)
			{
				continue;
			}

			for(int j=0; j<g[cur.first].size(); j++)
			{
				q.push({g[cur.first][j], cur.second-1});
				dp[g[cur.first][j]] += dp[s];
				dp[g[cur.first][j]]%=998244353;
			}
		}
	}

	for(int i=1; i<=N; i++)
	{
		if(g[i].size()==0)
		{
			ans += dp[i];
			ans%=998244353;
		}
	}
	cout << ans;
}