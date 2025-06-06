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
    while (T--)
    {
        int dp[22][10002] = {};
        int coin[22] = {};
		cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> coin[i];
        }
        cin >> M;
        sort(coin + 1, coin + N + 1);

		for (int i = 1; i <= N; i++)
        {
			dp[i][coin[i]] = 1;
			dp[21][coin[i]]++;
            for (int j = coin[i]+1; j <= M; j++)
            {
                dp[i][j] = dp[21][j-coin[i]];
                dp[21][j] += dp[i][j];
            }
        }


		cout << dp[21][M] << "\n";
    }
}