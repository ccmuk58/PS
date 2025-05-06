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

    string s;
    cin >> s;

    if (s[0] == 'E')
        cout << 'I';
    else
        cout << 'E';

    if (s[1] == 'S')
        cout << 'N';
    else
        cout << 'S';

    if (s[2] == 'F')
        cout << 'T';
    else
        cout << 'F';

    if (s[3] == 'P')
        cout << 'J';
    else
        cout << 'P';
}