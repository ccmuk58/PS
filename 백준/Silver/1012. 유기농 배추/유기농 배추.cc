#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };

int M, N, K, T;
int m[52][52];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

	while(T--)
	{
		int cnt = 0;
		cin >> M >> N >> K;
		while(K--)
		{
			int x, y;
			cin >> x >> y;
			m[y+1][x+1] = 1;
		}

		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)
			{
				queue<pi> q;
				if(m[i][j]==0) continue;
				
				cnt++;
				m[i][j]=0;
				q.push({i,j});
				while(!q.empty())
				{
					pi now = q.front();
					q.pop();
					int y = now.first;
					int x = now.second;
					for(int k=0; k<4; k++)
					{
						int ny = y+dy[k];
						int nx = x+dx[k];
						if(m[ny][nx] == 1)
						{
							m[ny][nx] = 0;
							q.push({ny, nx});
						}
					}
				}
				
			}
		}
		cout << cnt << "\n";
	}
	
	
}
