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
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int par[200002] = {};
int c[200002] = {};
int vstd[200002] = {};
vector<ll> v[200002];
ll ans = 0;
void dfs(int cur, int pc)
{
	vstd[cur] = true;
	if(pc != c[cur]) ans++;
	for(int i=0; i<v[cur].size(); i++)
	{
		if(vstd[v[cur][i]]) continue;
		dfs(v[cur][i], c[cur]);
	}

}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> A;
		c[i+1] = A;
	}


	for(int i=0; i<N-1; i++)
	{
		cin >> A >> B;

		v[A].push_back(B);
		v[B].push_back(A);
	}
	dfs(1, 0);

	cout << ans;
}   