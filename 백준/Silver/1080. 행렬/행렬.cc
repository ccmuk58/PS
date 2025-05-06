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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    vector<int> v;

    cin >> N >> M;

    int from[N + 2][M + 2];
    int to[N + 2][M + 2];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            from[i][j] = c - '0';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            char c;
            cin >> c;
            to[i][j] = c - '0';
        }
    }

    int cnt = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (from[i][j] != to[i][j])
            {
                cnt++;
                for (int k = 0; k < 3; k++)
                {
                    for (int o = 0; o < 3; o++)
                    {
                        from[i + k][j + o] = abs(from[i + k][j + o] - 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M ; j++)
        {
            if (from[i][j] != to[i][j])
            {
				cout << -1;
				return 0 ;
			}
		}
	}
	
	cout << cnt;
}