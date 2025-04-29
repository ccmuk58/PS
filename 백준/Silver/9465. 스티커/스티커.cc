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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> T;

	while(T--)
	{
		cin >> N;
		int dp[N][2] = {};
		int arr[N][2] = {};
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<N; j++)
			{
				cin >> arr[j][i];
			}
		}

		for(int i=0; i<2; i++)
			for(int j=0; j<1; j++)
				dp[j][i] = arr[j][i];
			dp[1][0] = dp[0][1] + arr[1][0];
			dp[1][1] = dp[0][0] + arr[1][1];
		
		for(int j=2; j<N; j++)
		{
			dp[j][0] = max(dp[j][0], dp[j-2][0] + arr[j][0]) ;
			dp[j][0] = max(dp[j][0], dp[j-2][1] + arr[j][0]) ;
			dp[j][0] = max(dp[j][0], dp[j-1][1] + arr[j][0]) ;
			
			dp[j][1] = max(dp[j][1], dp[j-2][0] + arr[j][1]) ;
			dp[j][1] = max(dp[j][1], dp[j-2][1] + arr[j][1]) ;
			dp[j][1] = max(dp[j][1], dp[j-1][0] + arr[j][1]) ;
		}
			cout << max(dp[N-1][0], dp[N-1][1]) << "\n";
		}
	
}