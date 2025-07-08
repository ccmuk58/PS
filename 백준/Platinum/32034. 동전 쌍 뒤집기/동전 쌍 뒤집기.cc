#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    vector<int> v;

    cin >> T;
    while (T--)
    {
        stack<int> s;
        cin >> N;
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            char c;
            cin >> c;
            if (c == 'T')
            {
                if (s.empty())
                {
                    s.push(i);
                }
                else if ((i - s.top()) % 2 == 1)
                {
                    ans += i - s.top();
                    s.pop();
                }
                else
                {
                    s.push(i);
                }
            }
        }

        if (s.empty())
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
}