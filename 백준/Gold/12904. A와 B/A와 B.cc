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
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

string s;
string t;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> s >> t;

    while(s.length() < t.length())
    {
		if(t[t.length()-1] == 'B')
		{
			t.erase(t.length()-1);
			reverse(t.begin(), t.end());
		}
		else
		{
			t.erase(t.length()-1);
		}
    }
    if (s == t)
        cout << 1;
    else
        cout << 0;
}