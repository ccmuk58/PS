#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
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
	
	while(true)
	{
		ll ans=0;
		cin >> W >> H;
		bool m[H+2][W+2]={};
		if(W==0 && H==0) return 0;

		for(int i=1; i<=H; i++)
		{
			for(int j=1; j<=W; j++)
			{
				cin >> m[i][j];
			}
		}

		
		for(int i=1; i<=H; i++)
		{
			for(int j=1; j<=W; j++)
			{
				queue<pi> q;
				if(m[i][j]==0)
					continue;
				q.push({i,j});
				m[i][j] = 0;
				while(!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for(int i=0; i<8; i++)
					{
						int ny = y+dy[i];
						int nx = x+dx[i];
						if(m[ny][nx]==1)
						{
							m[ny][nx] = 0;
							q.push({ny,nx});
						}
					}
				}
				ans++;
			}
		}
		cout << ans << "\n";

	}
}