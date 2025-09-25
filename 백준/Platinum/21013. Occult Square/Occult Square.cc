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


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	


	cin >> N;

	if(N<5)
	{
		cout << -1;
		return 0;
	}

	int b[N+2][N+2] = {};

	for(int i=1; i<=N/2-1; i++)
	{
		b[i][i+1] = N;
		b[N-i+1][N-i] = N;
	}
	if(N%2==0)
	{
		b[N/2][1] = 2;
		b[N/2][N] = N-2;
		b[N/2+1][1] = N-2;
		b[N/2+1][N] = 2;
	}
	else
	{
		b[N/2][1] = 2;
		b[N/2][N] = N-2;
		b[N/2+2][1] = N-2;
		b[N/2+2][N] = 2;
		b[N/2+1][N/2+1] = N;
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}

	/*
	. 5 . . .
	3 . . . 2
	. . 5 . .
	2 . . . 3
	. . . 5 .


	. 6 . . . . 
	. . 6 . . . 
	4 . . . . 2 
	2 . . . . 4 
	. . . 6 . . 
	. . . . 6 . 

	. x . . . . . . .
	. . x . . . . . .
	. . . x . . . . .
	a . . . . . . . b
	. . . . x . . . .
	b . . . . . . . a
	. . . . . x . . .
	. . . . . . x . .
	. . . . . . . x .
	*/
}