#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e7 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll dp[102][12];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	// 1-10
	for(int i=2; i<=10; i++)
	{
		dp[1][i] = 1;
	}

	for(int i=2; i<=N; i++)
	{
		for(int j=1; j<=10; j++)
		{
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
		}
	}

	
	ll t = 0;
	for(int j=1; j<=10; j++)
	{
		t+= dp[N][j];
		t%=1000000000;
	}
	cout << t;
}
