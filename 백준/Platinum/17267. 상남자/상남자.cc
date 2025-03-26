#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {-1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e3 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int ans;
int board[LIMIT][LIMIT];
bool vstd[LIMIT][LIMIT];
pi start;
void solve()
{
    queue<pair<pi, pi>> q;
    q.push({start, {L, R}});
    ans++;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

		
        int y = cur.first.first;
        int x = cur.first.second;
        int l = cur.second.first;
        int r = cur.second.second;
        int ny = 0;
        int nx = 0;
		
		
		for(int i=0; i<2; i++)
		{
			ny = y + dy[i];
			while(ny >= 1 && ny <= N && !vstd[ny][x] && board[ny][x] == 0)
			{
				ans++;
				vstd[ny][x] = true;
				q.push({{ny, x}, {l, r}});
				ny+=dy[i];
			}
		}
        nx = x - 1;
        if (l > 0 && nx >= 1 && !vstd[y][nx] && board[y][nx] == 0)
        {
            ans++;
            vstd[y][nx] = true;
            q.push({{y, nx}, {l - 1, r}});
        }
        nx = x + 1;
        if (r > 0 && nx <= M && !vstd[y][nx] && board[y][nx] == 0)
        {
            ans++;
            vstd[y][nx] = true;
            q.push({{y, nx}, {l, r - 1}});
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    cin >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
			char c;
            cin >> c;
			board[i][j] = c-'0';
            if (board[i][j] == 2)
            {
                vstd[i][j] = true;
                board[i][j] = 0;
                start = {i, j};
            }
        }
    }
    solve();

	cout << ans;
}