#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e2 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int board[LIMIT];
bool visited[LIMIT];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i <= 110; i++) {
        board[i] = i;
    }
    while (N--) {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }
    while (M--) {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    queue<pi> q;
    // idx, cnt
    q.push({1, 0});
    visited[0] = true;
    while (true) {
        pi cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = cur.first + i;
            int nCnt = cur.second + 1;
            int realNext = board[next];
            if (visited[realNext]) continue;
            if (realNext > 100) continue;
            if (realNext == 100) {
                cout << nCnt;
                return 0;
            }
            visited[realNext] = true;
            q.push({realNext, nCnt});
        }
    }
}