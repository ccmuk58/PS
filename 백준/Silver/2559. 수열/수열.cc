#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e4 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int answer = INT_MIN;
int st, en, n, k, s;
vector<int> v;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    st = 0;
    en = k - 1;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 0; i <= k - 1; i++)
    {
        s += v[i];
    }
    for (int i = 0; i <= n - k; i++)
    {
        answer = max(answer, s);
        if (en == n - 1)
            break;
        else
        {
            s -= v[st];
			st++;
			en++;
            s += v[en];
        }
    }
    cout << answer;
}
