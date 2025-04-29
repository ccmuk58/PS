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

ll dp[40];
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	dp[0]=1;
	dp[2]=3;
	dp[4]=3*3+2;
	for(int i=6; i<=N; i+=2)
	{
		dp[i] += dp[i-2]*3;
		for(int j=i-4; j>=0; j-=2)
		{
			dp[i] += dp[j]*2;
		}
	}

	cout << dp[N];
	
}
