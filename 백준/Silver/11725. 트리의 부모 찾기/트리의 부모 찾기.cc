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

ll ans = 0;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	vector<ll> v[N+2];

	for(int i=0; i<N-1; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	bool vstd[N+2] = {};
	int par[N+2] = {};
	queue<int> q;

	vstd[1] = true;
	q.push(1);

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i=0; i<v[cur].size(); i++)
		{
			if(vstd[v[cur][i]]) continue;
			q.push(v[cur][i]);
			vstd[v[cur][i]] = true;
			par[v[cur][i]] = cur;
		}
	}

	for(int i=2; i<=N; i++)
		cout << par[i] << "\n";

}