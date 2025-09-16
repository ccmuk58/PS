#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = 0;
vector<ll> v;

int dp[502][502];
int a[502][502];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> N;

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=i; j++)
		{
			cin >> A;
			a[i][j] = A;
			dp[i][j] = A;
		}
	}

	
	int mx=0;
	for(int i=1; i<N; i++)
	{
		for(int j=1; j<=i; j++)
		{
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+a[i+1][j+1]);
		}
	}

	for(int i=1; i<=N; i++)
	{
		mx = max(dp[N][i], mx);
	}

	cout << mx;
	

}