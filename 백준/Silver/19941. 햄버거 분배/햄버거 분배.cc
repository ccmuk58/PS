#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using pip = pair<int, pi>;
using plp = pair<ll, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e9 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool used[20001] = {};
    string str;
    cin >> N >> K >> str;

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (str[i] != 'P')
            continue;

        int lo = i - K;
        int hi = i + K;
        if (lo < 0)
            lo = 0;
        if (hi >= N)
            hi = N - 1;

        for (int j = lo; j <= hi; j++)
        {
            if (str[j] == 'H' && !used[j])
            {
                used[j] = true;
                ans++;
                break;
            }
        }
    }
    cout << ans;
}