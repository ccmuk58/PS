#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr ll LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> K;
	ll ans =0;
	vector<ll> v;
	queue<ll> q[K+2];

	for(int i=0; i<K; i++)
	{
		cin >> A;
		v.push_back(A);
		q[A].push(i);
	}
	ll tab[N+2] = {};
	for(int i=1; i<=K; i++)
	{
		q[i].push(LMT);
	}
	for(int i=0; i<K; i++)
	{
		bool isCon = false;
		for(int j=0; j<N; j++)
		{
			if(tab[j]==0 || tab[j]==v[i])
			{
				tab[j] = v[i];
				q[v[i]].pop();
				isCon = true;
				break;
			}
		}
		if(isCon) continue;

		ll maxNext = 0;
		ll maxNextIdx = 0;
		for(int j=0; j<N; j++)
		{
			if(maxNext < q[tab[j]].front())
			{
				maxNext = q[tab[j]].front();
				maxNextIdx = j;
			}
		}
		q[v[i]].pop();
		tab[maxNextIdx] = v[i];
		ans++;
	}
	cout << ans;	

}