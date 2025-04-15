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

ll ans = 0;
int maxdp[2][3];
int mindp[2][3];
int cost[100000][3];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    }

    for(int i=0; i<3; i++)
    {
        maxdp[0][i] = cost[0][i];
        mindp[0][i] = cost[0][i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        maxdp[1][0] = max(maxdp[0][0] + cost[i + 1][0], maxdp[0][1] + cost[i + 1][0]);
        maxdp[1][1] = max(maxdp[0][0] + cost[i + 1][1], max(maxdp[0][1] + cost[i + 1][1], maxdp[0][2] + cost[i + 1][1]));
        maxdp[1][2] = max(maxdp[0][1] + cost[i + 1][2], maxdp[0][2] + cost[i + 1][2]);

		mindp[1][0] = min(mindp[0][0] + cost[i + 1][0], mindp[0][1] + cost[i + 1][0]);
		mindp[1][1] = min(mindp[0][0] + cost[i + 1][1], min(mindp[0][1] + cost[i + 1][1], mindp[0][2] + cost[i + 1][1]));
		mindp[1][2] = min(mindp[0][1] + cost[i + 1][2], mindp[0][2] + cost[i + 1][2]);

		swap(maxdp[0], maxdp[1]);
		swap(mindp[0], mindp[1]);
    }
	int minans = INT32_MAX;
	int maxans = 0;

	maxans = max(maxdp[0][0], max(maxdp[0][1], maxdp[0][2]));
	minans = min(mindp[0][0], min(mindp[0][1], mindp[0][2]));

	cout << maxans << " " << minans;
}