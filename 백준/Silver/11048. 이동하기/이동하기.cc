#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int score[1002][1002];
int dp[1002][1002];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> score[i][j];
		}
	}
	dp[1][1] = score[1][1];
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			int ddx[3] = {1, 0, 1};
			int ddy[3] = {0, 1, 1};
			
			for(int k=0; k<3; k++)
			{
				if(i+ddx[k] <= N && j+ddy[k] <= M)
				{
					dp[i+ddx[k]][j+ddy[k]] = max(dp[i+ddx[k]][j+ddy[k]],
						dp[i][j]+score[i+ddx[k]][j+ddy[k]]);
				}
			}
		}
	}

	cout << dp[N][M];
	
}