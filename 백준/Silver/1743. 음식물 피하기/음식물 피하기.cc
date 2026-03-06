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
	
	cin >> N >> M >> K;
	vector<ll> v;
	ll ans = 0;

	bool m[N+2][M+2] = {};

	for(int i=0; i<K; i++)
	{
		cin >> A >> B;
		m[A][B]=1;
	}

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			if(m[i][j]==0) continue;
			queue<pi> q;
			ll a = 0;

			q.push({i,j});
			m[i][j]=0;
			a++;
			
			while(!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for(int d=0; d<4; d++)
				{
					int ny = y+dy[d];
					int nx = x+dx[d];
					
					if(!m[ny][nx]) continue;
					
					m[ny][nx]=0;
					q.push({ny,nx});
					a++;
				}
			}
			ans = max(a, ans);
		}
	}
	cout << ans;

}