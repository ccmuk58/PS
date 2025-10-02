#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
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

    cin >> R >> S;
    int arr[R + 2][S + 2] = {};
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            char c;
            cin >> c;
            if (c == 'o')
                arr[i][j] = 1;
        }
    }

    ll ans = 0;
    ll t = 0;

	
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= S; j++)
		{
			if (arr[i][j] == 0)
				continue;
			if (arr[i + 1][j + 1] == 1)
				t++;
			if (arr[i][j + 1] == 1)
				t++;
			if (arr[i - 1][j + 1] == 1)
				t++;
			if (arr[i - 1][j] == 1)
				t++;
		}
	}

	ans = t;
	t=0;
    for (int ii = 1; ii <= R; ii++)
    {
        for (int jj = 1; jj <= S; jj++)
        {
			if(arr[ii][jj]==1) continue;
			t=0;

			arr[ii][jj]=1;
            for (int i = 1; i <= R; i++)
            {
                for (int j = 1; j <= S; j++)
                {
                    if (arr[i][j] == 0)
                        continue;
                    if (arr[i + 1][j + 1] == 1)
                        t++;
                    if (arr[i][j + 1] == 1)
                        t++;
                    if (arr[i - 1][j + 1] == 1)
                        t++;
                    if (arr[i - 1][j] == 1)
                        t++;
                }
            }
			ans = max(ans, t);
			arr[ii][jj]=0;
        }
    }
    cout << ans;
}