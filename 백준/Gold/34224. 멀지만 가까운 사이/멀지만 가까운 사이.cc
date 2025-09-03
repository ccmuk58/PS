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


bool vstd[500002] = {};
vector<pl> g[500002];
ll ans = 0;
map<ll, ll> m;
ll dis = 0;
void go(ll curN, ll lastdis)
{
		dis = (dis^lastdis);
		m[dis]++;

		for(int i=0; i<g[curN].size(); i++)
		{
			if(vstd[g[curN][i].first] == true)
				continue;
			
			vstd[g[curN][i].first] = true;
			go(g[curN][i].first, g[curN][i].second);
		}
		dis = (dis^lastdis);
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> N;


	for(int i=0; i<N-1; i++)
	{
		cin >> A >> B >> C;
		g[A].push_back({B, C});
		g[B].push_back({A, C});
	}

	vstd[1] = true;

	go(1, 0);
	for(auto& it : m)
	{
		for(int i=it.second-1; i>0; i--)
		{
			ans+=i;
		}
	}
	cout << ans;

}