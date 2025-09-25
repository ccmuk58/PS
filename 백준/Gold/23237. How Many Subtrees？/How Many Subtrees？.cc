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


bool vstd[12];
vector<int> v[12];
ll ans;
int dfs(int n)
{
	int ret = 1;

	for(int i=0; i<v[n].size();i++)
	{
		if(vstd[v[n][i]]) continue;
		vstd[v[n][i]]=true;
		ret *= dfs(v[n][i])+1;
	}
	ans += ret;
	return ret;

}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	ll t=1;
	while(true)
	{
		ans=0;
		cin >> N;
		fill(vstd, vstd+N, false);
		for(int i=0; i<N; i++)
		{
			v[i].clear();
		}
		
		if(N==0)break;
		for(int i=1; i<=N-1; i++)
		{
			cin >> A >> B;
			v[A].push_back(B);
			v[B].push_back(A);
		}
		vstd[0]=true;
		dfs(0);
		cout << "Case " << t << ": "<< ans << "\n";
		t++;
	}

}