#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};

constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int b[1502][1502];
pi p[1502][1502];
queue<pi> q;
queue<pi> nq;
int ans;
pi l1, l2;

pi find(pi a)
{
    if (a == p[a.first][a.second])
        return a;
    return p[a.first][a.second] = find(p[a.first][a.second]);
}
void uni(pi a, pi b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;

    p[b.first][b.second] = a;
}
void bfs()
{
    while (find(l1).first != find(l2).first || find(l1).second != find(l2).second)
    {
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (b[nx][ny] == 0)
                    continue;
                uni({x, y}, {nx, ny});
                if (b[nx][ny] == -1)
                {
                    b[nx][ny] = 1;
					for(int j=0; j<4; j++)
					{
						int nnx = nx+dx[j];
						int nny = ny+dy[j];
						if (b[nnx][nny] == 1)
						{
							uni({nx, ny}, {nnx, nny});
						}
					}
                    nq.push({nx, ny});
                }
            }
        }
        ans++;
        while (!nq.empty())
        {
            q.push(nq.front());
            nq.pop();
        }

    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            p[i][j] = {i, j};
        }
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            char c;
            cin >> c;
            if (c == 'L')
            {
                if (l1.first == 0)
                    l1 = {i, j};
                else
                    l2 = {i, j};
            }
            
			if (c == '.' || c=='L')
            {
                b[i][j] = 1;
                q.push({i, j});
                for (int d = 0; d < 4; d += 2)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (b[nx][ny] == 1)
                        uni({i, j}, {nx, ny});
                }
            }
            else
            {
                b[i][j] = -1;
            }
        }
    }
    bfs();
    cout << ans;
}