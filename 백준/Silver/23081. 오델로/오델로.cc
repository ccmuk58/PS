#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	char m[N+2][N+2]={};

	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin >> m[i][j];
		}
	}

	int mx=0;
	pi mxidx={0, 0};
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(m[i][j]=='.')
			{
				int cnt=0;
				for(int k=0; k<8; k++)
				{
					if(m[i+dy[k]][j+dx[k]]=='W')
					{
						int tcnt = 1;
						int ypos = dy[k];
						int xpos = dx[k];
						while(true)
						{
							ypos += dy[k];
							xpos += dx[k];
							if(m[i+ypos][j+xpos]=='.' || m[i+ypos][j+xpos]==0)
							{
								break;
							}
							else if(m[i+ypos][j+xpos]=='B')
							{
								cnt += tcnt;
								if(cnt > mx)
								{
									mx = cnt;
									mxidx = {j-1, i-1};
								}
								break;
							}
							tcnt++;
						}
					}
				}
			}
		}
	}

	if(mx==0)
	{
		cout << "PASS";
	}
	else
	{
		cout << mxidx.first << " " << mxidx.second << "\n";
		cout << mx;
	}

}