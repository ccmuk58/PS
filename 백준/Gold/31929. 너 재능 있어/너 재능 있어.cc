#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
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

int ans = 0;
vector<int> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    vector<int> w;
	w.push_back(0);
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        w.push_back(A);
    }

    cin >> M;
    vector<int> l;
	l.push_back(0);
    for (int i = 0; i < M; i++)
    {
        cin >> A;
        l.push_back(A);
    }
    cin >> K;
    int dp[N + 2][M + 2] = {};

	dp[1][0] = w[1];
	for(int i=2; i<=N; i++)
	{
		dp[i][0] = dp[i-1][0] + w[i];
	}
	dp[0][1] = -l[1];
	for(int i=2; i<=M; i++)
	{
		int mod = dp[0][i-1]%K;
		if(mod <= 0) mod += K;
		int loss = min(l[i], mod);
		dp[0][i] = dp[0][i-1] - loss;
	}

	for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
			int a = dp[i-1][j] + w[i];

			int mod = dp[i][j-1]%K;
			if(mod <= 0) mod += K;
			int loss = min(l[j], mod);
			int b = dp[i][j - 1] - loss;

			dp[i][j] = max(a, b);
        }
    }

	cout << dp[N][M];
}