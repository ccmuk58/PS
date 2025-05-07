#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	ll inha[N+2][N+2]={};
	ll psum[N+2][N+2]={};
	ll boom[N+2][N+2]={};
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin >> inha[i][j];
		}
	}

	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			psum[i][j] = psum[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];

			ll b = -(psum[i][j] + inha[i][j]);
			int m=M/2;
			boom[i+m][j+m] = b;
			psum[i][j] += b;
			psum[i+M][j] -= b;
			psum[i][j+M] -= b;
			psum[i+M][j+M] += b;
		}
	}

	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cout << boom[i][j] << " ";
		}
		cout << "\n";
	}
	

}