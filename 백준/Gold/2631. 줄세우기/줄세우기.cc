#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    vector<int> v;
    vector<int> dp;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    dp.push_back(v[0]);

    for (int i = 1; i < N; i++)
    {
        if (v[i] > dp.back())
        {
            dp.push_back(v[i]);
        }
        else
        {
            dp[lower_bound(dp.begin(), dp.end(), v[i])-dp.begin()] = v[i];
        }
    }
	cout << N-dp.size();
}