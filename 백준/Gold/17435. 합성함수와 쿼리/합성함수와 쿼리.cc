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


int sp[22][200000+2] = {};
int main()
{
	cin.tie(0)->sync_with_stdio(0);


	cin >> M;
	for(int i=1; i<=M; i++)
	{
		cin >> sp[0][i];
	}

	for(int i=1; i<=20; i++)
	{
		for(int j=1; j<=M; j++)
		{
			// 2^i : 1 2 4 8
			sp[i][j] = sp[i-1][sp[i-1][j]];
		}
	}

	cin >> Q;
	while(Q--)
	{
		// 3 1
		cin >> N >> X;
		for(int i=0; i<=20; i++)
		{
			if(N&(1<<i)) 
			{
				X = sp[i][X];
			}
		}
		cout << X << "\n";
	}
}