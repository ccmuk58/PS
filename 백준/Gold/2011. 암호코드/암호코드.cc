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
ll dp[5002];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;

    if (str[0] == '0')
    {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    if (str[1] > '0')
        dp[1] = dp[0];

    int n = stoi(str.substr(0, 2));
    if (n <= 26 && n >= 10)
        dp[1] = dp[1] + 1;

    for (int i = 2; i < str.length(); i++)
    {
        if (str[i] > '0')
            dp[i] = (dp[i] + dp[i - 1]) % 1000000;

        int n = stoi(str.substr(i-1, 2));
        if (n <= 26 && n >= 10)
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
    }
    cout << dp[str.length() - 1];
}