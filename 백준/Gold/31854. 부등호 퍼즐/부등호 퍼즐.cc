#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int A, B, C, N, M, K, L, R;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

int indeg[1002][1002];
bool b[1002][1002][4];
int ans[1002][1002];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            char c;
            cin >> c;
            if (c == '>')
            {
                indeg[i][j]++;
                b[i][j + 1][2] = true;
            }
            else
            {
                indeg[i][j + 1]++;
                b[i][j][0] = true;
            }
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            if (c == '>')
            {
                indeg[i][j]++;
                b[i + 1][j][1] = true;
            }
            else
            {
                indeg[i + 1][j]++;
                b[i][j][3] = true;
            }
        }
    }

    queue<pi> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (indeg[i][j] == 0)
                q.push({i, j});
        }
    }
    int cnt = 1;
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();
        ans[y][x] = cnt++;

        for (int j = 0; j < 4; j++)
        {
            if (b[y][x][j] == true)
            {
				int ny = y+dy[j];
				int nx = x+dx[j];
                indeg[ny][nx]--;
                if (indeg[ny][nx] == 0)
                    q.push({ny, nx});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "\n";
    }
}