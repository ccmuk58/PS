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
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int board[102][102];
ll dp[102][102];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
	vector<int> v;
	for(int i=0; i<N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int dp[1002] = {};
	
	dp[0] = v[0];
	int back = 0;
	for(int i=1; i<N; i++)
	{
		if(dp[back] < v[i])
		{
			dp[++back] = v[i];
		}
		else
		{
			dp[lower_bound(dp, dp+back+1, v[i])-dp] = v[i];
		}
	}
	cout << back+1;
}