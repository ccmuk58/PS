#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N;
    char m[N + 2][M + 2] = {};
    ll w = 0;
    ll b = 0;
	

    queue<pi> q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
			if(m[i][j]=='X') continue;
			char c = m[i][j];
			q.push({i,j});
			int p=1;
			m[i][j] = 'X';
			
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny < 1 || ny > N || nx < 1 || nx > M)
                        continue;
                    if (m[ny][nx] != c)
                        continue;
					p++;
                    m[ny][nx] = 'X';
                    q.push({ny, nx});

                }
            }
			if (c == 'W')
				w+=pow(p,2);
			else	
				b+=pow(p,2);

        }
    }

	cout << w <<  " " << b;
}