#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int number = 1000002;
int primeNum[1000002];
void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	primeNumberSieve();

	cin >> N;
	vector<ll> v[N+2];
	ll ans = 0;
	vector<ll> pn;
	
	for(int i=2; i<1000001; i++)
	{
		if(primeNum[i]!=0)
		{
			pn.push_back(i);
		}
	}


	for(int i=2; i<=N; i++)
	{
		cin >> A;
		v[A].push_back(i);
		v[i].push_back(A);
	}

	queue<pi> q;
	bool vstd[N+2] = {};
	int dis[1000002] = {};
	q.push({1, 0});
	vstd[1]=true;
	ans++;
	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for(int i=0; i<v[cur.first].size(); i++)
		{
			if(vstd[v[cur.first][i]])continue;
			vstd[v[cur.first][i]] = true;
			q.push({v[cur.first][i], cur.second+1});
			dis[cur.second+1]++;
		}
	}


	for(int i=0; i<pn.size(); i++)
	{
		ll t = 1;
		for(int j=pn[i]; j<1000000; j+=pn[i])
		{
			t += dis[j];
		}
		ans = max(ans, t);
	}
	cout << ans;
}