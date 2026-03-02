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

vector<pi> v[1002];
bool isFind = false;
bool vstd[1002]={};
ll ans = 0;
void go(int cur, int cost)
{
	if(cur == B)
	{
		isFind=true;
		ans = cost;
		return;
	}
	for(int i=0; i<v[cur].size(); i++)
	{
		if(vstd[v[cur][i].first]) continue;
		vstd[v[cur][i].first]=true;
		go(v[cur][i].first, cost+v[cur][i].second);
		vstd[v[cur][i].first]=false;
		if(isFind)return;
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	for(int i=1; i<N; i++)
	{
		cin >> A >> B >> C;
		v[A].push_back({B, C});
		v[B].push_back({A, C});
	}

	for(int i=0; i<M; i++)
	{
		cin >> A >> B;
		vstd[A]=true;
		go(A, 0);
		vstd[A]=false;
		isFind=false;
		cout << ans << "\n";
		ans = 0;
	}

}
