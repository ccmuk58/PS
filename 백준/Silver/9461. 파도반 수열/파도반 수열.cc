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

ll dp[102];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	for(int i=4; i<=100; i++)
	{
		dp[i] = dp[i-2] + dp[i-3];
	}
	cin >> T;

	while(T--)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}	
}