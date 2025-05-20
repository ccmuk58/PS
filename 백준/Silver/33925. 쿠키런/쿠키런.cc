#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using ll = long long;
int A,B,C,D,E,N,J,S,H,M,K,W,X,Y,Z;

char m[4][102]={};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> J >> S >> H >> K;

	for(int i=0; i<=2; i++)
	{
		for(int j=1; j<=N; j++)
			cin >> m[i][j];
	}


	for(int i=2; i<N; i++)
	{
		if(m[1][i]=='v')
		{
			if(S>0)
				S--;
			else 
				H-=K;
		}
		if(m[2][i]=='^' && m[1][i]=='.')
		{
			if(J>=1)
				J--;
			else 
				H-=K;
		}

		if(H<=0)
		{
			cout << -1;
			return 0;
		}
	}
	for(int i=2; i<N; i++)
	{
		if(m[1][i]=='^')
		{
			if(J>=2)
				J-=2;
			else 
				H-=K;
		}

		if(H<=0)
		{
			cout << -1;
			return 0;
		}
	}
	cout << H;
}