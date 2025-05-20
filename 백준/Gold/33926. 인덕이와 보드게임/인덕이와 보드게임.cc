#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using ll = long long;
using pl = pair<ll,ll>;
using pli = pair<ll,int>;
int A,B,C,D,E,N,M,K,W,X,Y,Z;

int dy[2] = {0, 1};
int dx[2] = {1, 0};
bool black[1002][1002];
ll b[1002][1002];
ll ans[1002][1002][2];

/*
void solve(int y, int x)
{
	if(black[y+1][x])
	{
		ps[y+1][x][0] = min(ps[y+1][x][0] , -(ps[y][x][0] + b[y+1][x]));
		ps[y+1][x][1] = max(ps[y+1][x][1] , -(ps[y][x][0] + b[y+1][x]));
		ps[y+1][x][0] = min(ps[y+1][x][0] , -(ps[y][x][1] + b[y+1][x]));
		ps[y+1][x][1] = max(ps[y+1][x][1] , -(ps[y][x][1] + b[y+1][x]));
		
	}
	else{
		ps[y+1][x][0] = min(ps[y+1][x][0] , ps[y][x][0] + b[y+1][x]);
		ps[y+1][x][1] = max(ps[y+1][x][1], ps[y][x][1]+b[y+1][x]);
	}
	
	if(black[y][x+1])
	{
		ps[y][x+1][0] = min(ps[y][x+1][0] , -(ps[y][x][0] + b[y][x+1]));
		ps[y][x+1][0] = min(ps[y][x+1][0] , -(ps[y][x][1] + b[y][x+1]));
		ps[y][x+1][1] = max(ps[y][x+1][1] , -(ps[y][x][0] + b[y][x+1]));
		ps[y][x+1][1] = max(ps[y][x+1][1] , -(ps[y][x][1] + b[y][x+1]));
		
	}
	else{
		ps[y][x+1][0] = min(ps[y][x+1][0] , ps[y][x][0] + b[y][x+1]);
		ps[y][x+1][1] = max(ps[y][x+1][1], ps[y][x][1]+b[y][x+1]);
	}
	if(y+1<=N)
		solve(y+1, x);
	if(x+1<=M)
		solve(y, x+1);
}
		*/
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			{
				ans[i][j][0] = 1000000000000;
				ans[i][j][1] = -1000000000000;
			}

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			{
				cin >> b[i][j];
			}

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin >> black[i][j];



	for(int i=1; i<=N; i++)
	{
		ans[i][1][0] = b[i][1] + ans[i-1][1][0];
		ans[i][1][1] = b[i][1] + ans[i-1][1][0];
		if(black[i][1])
		{
			ll t = ans[i][1][0];
			ans[i][1][0] = -ans[i][1][1];
			ans[i][1][1] = -t;
		}
			

	}
	for(int j=1; j<=M; j++)
	{
		ans[1][j][0] = b[1][j]+ans[1][j-1][0];
		ans[1][j][1] = b[1][j]+ans[1][j-1][1];
		if(black[1][j])
		{
			ll t = ans[1][j][0];
			ans[1][j][0] = -ans[1][j][1];
			ans[1][j][1] = -t;
		}
	}

	
	for(int i=2; i<=N; i++)
	{
		for(int j=2; j<=M; j++)
		{
			if(black[i][j])
			{
				ans[i][j][0] = -(max(ans[i-1][j][1], ans[i][j-1][1])+b[i][j]);
				ans[i][j][1] = -(min(ans[i-1][j][0], ans[i][j-1][0])+b[i][j]);
			
			}
			else
			{
				ans[i][j][0] = min(ans[i-1][j][0], ans[i][j-1][0])+b[i][j];
				ans[i][j][1] = max(ans[i-1][j][1], ans[i][j-1][1])+b[i][j];
			}
		}
	}
	cout << ans[N][M][1];

	
}