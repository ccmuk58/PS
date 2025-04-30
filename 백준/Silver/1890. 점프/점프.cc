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

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    dp[1][1] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dp[i][j] == 0 || board[i][j] == 0)
                continue;
            int ny = board[i][j] + j;
            if (ny <= N)
                dp[i][ny] += dp[i][j];

            int nx = board[i][j] + i;
            if (nx <= N)
                dp[nx][j] += dp[i][j];

        }
    }

    cout << dp[N][N];
}