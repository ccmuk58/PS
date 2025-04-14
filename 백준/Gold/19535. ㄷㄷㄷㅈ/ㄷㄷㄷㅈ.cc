#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<ll> v[300002];
bool vstd[300002];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for(ll i=0; i<N-1; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	
	for(ll i=1; i<=N; i++)
	{
		if(v[i].size() >= 3)
		{
			G += v[i].size()*(v[i].size()-1)*(v[i].size()-2) / 6;
		}
	}
	queue <ll> q;
	
	for(ll i=1; i<=N; i++)
	{
		if(v[i].size() >= 1)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		ll cur = q.front();
		q.pop();
		if(vstd[cur]) continue;
		vstd[cur] = true;
		for(ll i=0; i<v[cur].size(); i++)
		{
			if(!vstd[v[cur][i]])
			{
				if(v[v[cur][i]].size() == 1) continue;
				D += (v[cur].size()-1) * (v[v[cur][i]].size()-1);
			}
		}
	}
	if(D>G*3)
		cout << "D";
	else if(D<G*3)
		cout << "G";
	else
		cout << "DUDUDUNGA";
}