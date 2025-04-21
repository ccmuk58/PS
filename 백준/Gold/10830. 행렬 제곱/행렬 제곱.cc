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
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll m[1048578][5][5];

void mul(){


}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> B;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			cin >> m[1][i][j];
			m[1][i][j] %= 1000;
		}

	for(int d=2; d<=1048576; d*=2)
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				for(int k=0; k<N; k++)
				{
					m[d][i][j] += m[d/2][i][k] * m[d/2][k][j];
				}
				m[d][i][j] %= 1000;
			}
		}
	}

	ll x=1048576;
	ll ans[5][5] = {};
	ll nxans[5][5] = {};
	for(int i=0; i<N; i++)
	{
		ans[i][i] = 1;
	}

	while(B > 0)
	{
		ll nans[5][5] = {};
		
		if(B<x)
		{
			x/=2;
			continue;
		}

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				for(int k=0; k<N; k++)
				{
					nans[i][j] += ans[i][k] * m[x][k][j];
				}
				nans[i][j] %= 1000;
			}
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				ans [i][j] = nans[i][j];
			}
		}

		B-=x;
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}