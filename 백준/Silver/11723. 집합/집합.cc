#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y,
    Z;
int sx, sy, ex, ey;
int cx, cy, r;
map<int, int> m;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M;

    string cmd;
    int n;
    while (M--) {
        cin >> cmd;
        if (cmd == "all")
            for (int i = 1; i <= 20; i++) m[i] = 1;
        else if (cmd == "empty")
            for (int i = 1; i <= 20; i++) m[i] = 0;
        else {
            cin >> n;
            if (cmd == "add")
                m[n] = 1;
            else if (cmd == "remove")
                m[n] = 0;
            else if (cmd == "check") {
                if (m[n] == 1)
                    cout << 1 << "\n";
                else
                    cout << 0 << "\n";
            } else if (cmd == "toggle")
                m[n] = abs(m[n] - 1);
        }
    }
}
