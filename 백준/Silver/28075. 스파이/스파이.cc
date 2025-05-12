#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int N, M;
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int score[4][5] = {};
    cin >> N >> M;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> score[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            stack<pair<pi, pi>> s;
            s.push({{1, score[i][j]}, {i, j}});
            while (!s.empty())
            {
                int d = s.top().first.first;
                int sc = s.top().first.second;
                int y = s.top().second.first;
                int x = s.top().second.second;
                s.pop();
                if (d == N)
                {
                    if (sc >= M)
                        ans++;
                    continue;
                }
                for (int k = 1; k <= 2; k++)
                {
                    for (int o = 1; o <= 3; o++)
                    {
                        int ny = k;
                        int nx = o;
                        if (nx == x)
                            s.push({{d + 1, sc + score[ny][nx] / 2}, {ny, nx}});
                        else
                            s.push({{d + 1, sc + score[ny][nx]}, {ny, nx}});
                    }
                }
            }
        }
    }
    cout << ans;
}