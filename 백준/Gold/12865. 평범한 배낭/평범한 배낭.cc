#include <bits/stdc++.h>
using namespace std;
int N, K;
int W[101] = {}, V[101] = {};
int dp[101][100001] = {};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            }
        }
    }
    cout << dp[N][K];
}