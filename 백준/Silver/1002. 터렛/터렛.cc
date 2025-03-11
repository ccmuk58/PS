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
int jx, jy, jr, px, py, pr;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> jx >> jy >> jr >> px >> py >> pr;

        double dis = sqrt(pow(px - jx, 2) + pow(py - jy, 2));
        double range = pr + jr;

        if (jx == px && jy == py && jr == pr) {
            cout << -1 << "\n";
            continue;
        }

        if (range < dis)
            cout << 0 << "\n";
        else if (range > dis) {
            if (dis + jr < pr || dis + pr < jr)
                cout << 0 << "\n";
            else if (dis + jr == pr || dis + pr == jr)
                cout << 1 << "\n";
            else
                cout << 2 << "\n";

        } else
            cout << 1 << "\n";
    }
}
