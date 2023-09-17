#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
constexpr int LIMIT = 1e3 + 4;

int N;
int board[LIMIT][LIMIT];
// {가로, 세로, 우하대각, 좌하대각}
int len[LIMIT][LIMIT][4];
int result = 1;
stack<pi> s;
int lenCnt = 0;

void func(int d) {
    while (!s.empty()) {
        auto [y, x] = s.top();
        s.pop();
        len[y][x][d] = lenCnt;
    }
    result = max(result, lenCnt);
    lenCnt=0;
}

void CheckRow() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 1) {
                lenCnt++;
                s.push({i, j});
            } else {
                func(0);
            }
        }
        func(0);
    }
}

void CheckCol() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[j][i] == 1) {
                lenCnt++;
                s.push({j, i});
            } else {
                func(1);
            }
        }
        func(1);
    }
}

void CheckDiaLT() {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j + i <= N; j++) {
            if (board[j][j + i] == 1) {
                lenCnt++;
                s.push({j, j + i});
            } else {
                func(2);
            }
        }
        func(2);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j + i <= N; j++) {
            if (board[j + i][j] == 1) {
                lenCnt++;
                s.push({j + i, j});
            } else {
                func(2);
            }
        }
        func(2);
    }
}
void CheckDiaRT() {
    for (int i = 0; i < N; i++) {
        for (int j = N; j - i > 0; j--) {
            int y = N - j;
            int x = j - i;
            if (board[y][x] == 1) {
                lenCnt++;
                s.push({y, x});
            } else {
                func(3);
            }
        }
        func(3);
    }
    for (int i = 0; i < N; i++) {
        for (int j = N; N - j + i <= N; j--) {
            int y = N - j + i;
            int x = j;
            if (board[N - j + i][j] == 1) {
                lenCnt++;
                s.push({y, x});
            } else {
                func(3);
            }
        }
        func(3);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    CheckRow();
    CheckCol();
    CheckDiaLT();
    CheckDiaRT();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(board[i][j] == 2)
            {
                result = max(result, len[i][j-1][0] + 1 + len[i][j+1][0]);
                result = max(result, len[i-1][j][1] + 1 + len[i+1][j][1]);
                result = max(result, len[i-1][j-1][2] + 1 + len[i+1][j+1][2]);
                result = max(result, len[i-1][j+1][3] + 1 + len[i+1][j-1][3]);
            }
        }
    }

    cout <<  result;
}