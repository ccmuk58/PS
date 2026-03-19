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
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string str, boom;
    cin >> str >> boom;

    int blen = boom.size();
    vector<char> s;
    s.reserve(str.size());

    for (char c : str)
    {
        s.push_back(c);

        if (s.back() == boom[blen - 1] && (int)s.size() >= blen)
        {
            bool match = true;
            int slen = s.size();
            for (int i = 0; i < blen; i++)
            {
                if (s[slen - blen + i] != boom[i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                for (int i = 0; i < blen; i++)
                    s.pop_back();
            }
        }
    }

    if (s.empty())
        cout << "FRULA\n";
    else
    {
        for (char c : s)
            cout << c;
        cout << '\n';
    }

    return 0;
}