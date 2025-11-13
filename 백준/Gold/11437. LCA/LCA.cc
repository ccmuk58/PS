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
ll ans = 0;

int lv[50002];
int par[50002];
vector<int> v[50002];
void dfs(int n, int l, int p)
{
	lv[n] = l;
	par[n] = p;

	for(int i=0; i<v[n].size(); i++)
	{
		if(par[v[n][i]]==0)
		{
			dfs(v[n][i], l+1, n);
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for(int i=0; i<N-1; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	dfs(1, 0, -1);

	cin >> M;

	while(M--)
	{
		cin >> A >> B;
		if(lv[A]<lv[B])swap(A,B);

		while(lv[A]>lv[B])
		{
			A = par[A];
		}

		while(A != B)
		{
			A=par[A];
			B=par[B];
		}
		cout << A << "\n";
	}
}