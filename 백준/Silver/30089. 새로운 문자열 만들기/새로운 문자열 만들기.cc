#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = 0;
vector<ll> v;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    while (T--)
    {
        string s, sp;
        cin >> s;
        sp = s;
        reverse(sp.begin(), sp.end());
        int st = s.length()-1;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < sp.length() - i; j++)
            {
                if (s[i + j] != sp[j])
                    break;
                if (j == sp.length() - i -1)
                {
                    st = sp.length() - i;
                    i = s.length();
                    break;
                }
            }
        }
		for(int i=st; i<sp.length(); i++)
		{
			s.push_back(sp[i]);
		}

		cout << s << "\n";

    }
}