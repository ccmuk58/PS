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

char board[52][52] = {};
int idx[26] = {};
map<char, int> m;
string ans;
string nickname;

void compLv()
{
    int cCnt[26] = {};
    int mxLv = 100000;
    for (int i = 0; i < S; i++)
    {
        cCnt[nickname[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cCnt[i] == 0)
            continue;
        mxLv = min(mxLv, (int)(m[i] / cCnt[i]));
    }
    C = mxLv;
}
void move()
{
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> S;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c;
            m[c - 'a']++;
        }
    }
    cin >> nickname;

    compLv();

    cout << C << " ";

    int lv = 0;
    queue<pi> q;
    int sx = 1;
    int sy = 1;
    q.push({sy, sx});
    int nickIdx = 0;
    bool vstd[52][52] = {};
    while (lv < C)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (board[y][x] == nickname[nickIdx])
        {
            nickIdx = (nickIdx + 1) % nickname.length();
            if (nickIdx == 0)
            {
                lv++;
            }
            board[y][x] = 0;
            while (sx < x)
            {
                sx++;
                ans.push_back('R');
            }
            while (sx > x)
            {
                sx--;
                ans.push_back('L');
            }
            while (sy < y)
            {
                sy++;
                ans.push_back('D');
            }
            while (sy > y)
            {
                sy--;
                ans.push_back('U');
            }
            while (!q.empty())
            {
                q.pop();
            }

            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= M; j++)
                {
                    vstd[i][j] = false;
                }
            }
            ans.push_back('P');
            sx = x;
            sy = y;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > M || ny <= 0 || ny > N)
                continue;
            if (vstd[ny][nx])
                continue;

            q.push({ny, nx});
            vstd[ny][nx] = true;
        }
    }
    while (sx < M)
    {
        sx++;
        ans.push_back('R');
    }
    while (sy < N)
    {
        sy++;
        ans.push_back('D');
    }
    cout << ans.length() << "\n";
    cout << ans;
}