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
	
	cin >> N >> M;
	char m[N+2][M+2]={};
	pl v[N+2][M+2]={};
	int vstd[N+2][M+2]={};
	

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> m[i][j];
		}
	}
	ll fllidx = 0;
	
	for(int y=1; y<=N; y++)
	{
		for(int x=1; x<=M; x++)
		{
			if(vstd[y][x]==1 || m[y][x]=='1') continue;
			
			queue<pl> q;
			q.push({y,x});
			vstd[y][x] = -1;
			ll fll = 1;
			fllidx++;
			while(!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for(int d=0; d<4; d++)
				{
						int ny = cur.first+dy[d];
						int nx = cur.second+dx[d];

						if(vstd[ny][nx]!=0 || m[ny][nx]=='1' || ny>N || ny<1  || nx>M || nx<1) 
							continue;

						vstd[ny][nx] = -1;
						q.push({ny, nx});
						fll++;
				}
			}

			fll%=10;
			q.push({y,x});
			vstd[y][x] = 1;
			v[y][x].first = fll;
			v[y][x].second = fllidx;

			while(!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for(int yi=0; yi<4; yi++)
				{
					for(int xi=0; xi<4; xi++)
					{
						int ny = cur.first+dy[yi];
						int nx = cur.second+dx[xi];

						if(vstd[ny][nx]!=-1 || ny>N || ny<1  || nx>M || nx<1) 
							continue;

						vstd[ny][nx] = 1;
						v[ny][nx].first = fll;
						v[ny][nx].second = fllidx;
						q.push({ny, nx});
					}
				}
			}
		}
	}

	
	// for(int y=1; y<=N; y++)
	// {
	// 	for(int x=1; x<=M; x++)
	// 	{
	// 		cout << v[y][x].first;
	// 	}
	// 	cout << "\n";
	// }

	bool chk[N*M+2] = {};
	for(int y=1; y<=N; y++)
	{
		for(int x=1; x<=M; x++)
		{
			ll ans = 0;
			if(m[y][x]=='0') cout << 0;
			else
			{
				for(int d=0; d<4; d++)
				{
					if(chk[v[y+dy[d]][x+dx[d]].second]) continue;
					chk[v[y+dy[d]][x+dx[d]].second] = true;
					ans += v[y+dy[d]][x+dx[d]].first;
				}
				cout << (ans+1)%10;
				
				for(int d=0; d<4; d++)
				{
					chk[v[y+dy[d]][x+dx[d]].second] = false;
				}
			}
		}
		cout << "\n";
	}
}