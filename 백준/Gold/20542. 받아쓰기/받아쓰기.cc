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

	string a, b;
	cin >> N >> M;
	cin >> a >> b;

	a.insert(0,"0");
	b.insert(0,"0");
	int dp[N+2][M+2] = {};
	
	int afidx=0;
	int aeidx=0;
	int bfidx=0;
	int beidx=0;

	for(int i=1; i<=N; i++)
	{
		dp[i][0] = i;
	}
	for(int i=1; i<=M; i++)
	{
		dp[0][i] = i;
	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			if(a[i]=='i' && (b[j] == 'i' || b[j] == 'j' || b[j] == 'l' ))
			{
					dp[i][j] = dp[i-1][j-1];
			}
			else if(a[i]=='v' && (b[j] == 'w' || b[j] == 'v'))
			{
					dp[i][j] = dp[i-1][j-1];
			}
			else if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1])) + 1;
		}
	}
	
	cout << dp[N][M];
	
}