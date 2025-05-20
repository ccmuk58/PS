#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using ll = long long;
int A,B,C,D,E,N,M,K,W,X,Y,Z;
int dy[] = {-2,1,-1,2,2,1,-1,-2};
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int ans;
int b[100][100];

int vstd[100][100];

void solve(int s, int y, int x)
{
	ans = max(ans, s);	
	vstd[y][x]++;
	for(int i=0; i<8; i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || ny>=N || nx<0 || nx>=N)
			continue;
		vstd[ny][nx]++;
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(vstd[i][j]==0)
				solve(s+b[i][j],i, j);
		}
	}

	for(int i=0; i<8; i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || ny>=N || nx<0 || nx>=N)
			continue;
		vstd[ny][nx]--;
	}
	vstd[y][x]--;
	

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> b[i][j];
		}		
	}
	

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			solve(b[i][j],i,j);

	cout << ans;
}