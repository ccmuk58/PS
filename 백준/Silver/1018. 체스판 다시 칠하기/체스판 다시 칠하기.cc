#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e8 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y,
    Z;

int ans = LIMIT;
bool board[51][51];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'W') board[i][j] = true;
        }
    }

    bool chessBoard[9][9] = {};
    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            for (int k = 0; k < 2; k++) {
                for (int o = 0; o < 8; o++) {
                    for (int p = 0; p < 8; p++) {
                        // cout << o << ", " << p << "\n";
                        chessBoard[o][p] = board[i + o][j + p];
                    }
                }
                int cnt = 0;
                if (k == 1) {
					chessBoard[0][0] = !chessBoard[0][0];
					cnt++;
				}
                bool curChar = false;
                bool preChar = chessBoard[0][0];
                for (int y = 0; y < 8; y++) {
                    for (int x = 0; x < 8; x++) {
                        if (y == 0 && x == 0) x++;
                        curChar = chessBoard[y][x];
                        if ((x != 0 && preChar == curChar) || (x == 0 && preChar != curChar)) {
                            curChar = !curChar;
                            cnt++;
                        }
                        preChar = curChar;
                    }
                }
                if (cnt < ans) 
				{
					ans = cnt;
				}

            }
        }
    }
    cout << ans;
}