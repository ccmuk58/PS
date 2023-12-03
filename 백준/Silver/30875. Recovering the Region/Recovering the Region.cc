#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
constexpr int dy[] = {0, 0, 1, -1};
constexpr int dx[] = {1, -1, 0, 0};
int n;
int board[52][52];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> board[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
}