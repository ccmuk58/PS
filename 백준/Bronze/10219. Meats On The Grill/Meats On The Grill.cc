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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--)
    {
        cin >> H >> W;
		char b[W+1][H+1] = {};
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
				cin >> b[i][j];
            }
        }

		
        for (int i = 0; i < H; i++)
        {
            for (int j = W-1; j >= 0; j--)
            {
				cout << b[i][j];
			}
			cout << "\n";
		}
    }
}