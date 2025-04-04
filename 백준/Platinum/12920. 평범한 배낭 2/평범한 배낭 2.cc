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

int dp[10002][10002] = {};
int ipow[16] = {1, 2};
vector<pi> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
	v.push_back({0,0});
	for(int i=2; i<16; i++)
	{
		ipow[i] = ipow[i-1]*2;
	}
	for (int i = 1; i <= N; i++)
    {
        cin >> W >> C >> K;
		while(K>0)
		{
			int n=0;
			int j=1;
			while(j<=K)
			{
				v.push_back({W*j, C*j});
				K-=j;
				j=ipow[++n];
			}
		}
    }

    for (int i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= M; j++)
        {
			int w = v[i].first;
			int c = v[i].second;
            if (w > j)
                dp[i][j] = dp[i-1][j];
            else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + c);
        }
    }
	cout << dp[v.size()][M];
}