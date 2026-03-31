#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll dp[21][21][21];
bool vstd[21][21][21];
ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (vstd[a][b][c]) return dp[a][b][c];
    vstd[a][b][c] = true;

    ll& ret = dp[a][b][c];
    if (a < b && b < c)
        ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else
        ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
		cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1) break;
        cout << "w(" << A << ", " << B << ", " << C << ") = " << w(A, B, C) << "\n";
    }
}