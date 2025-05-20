#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using ll = long long;
int A,B,C,D,E,N,M,K,W,X,Y,Z;
bool b[5][3];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M >> K;
	b[N-1][M-1]=true;
	string s;

	cin >> s;

	for(int i=0; i<K; i++)
	{
		if(s[i]=='A')
		{
			swap(b[0][0], b[2][0]);
			swap(b[0][1], b[2][1]);
			swap(b[1][0], b[3][0]);
			swap(b[1][1], b[3][1]);
		}
		else if(s[i]=='B')
		{
			swap(b[0][0], b[1][1]);
			swap(b[0][1], b[1][0]);
			swap(b[2][0], b[3][1]);
			swap(b[3][0], b[2][1]);
		}
		else if(s[i]=='C')
		{

			swap(b[0][0], b[3][1]);
			swap(b[0][1], b[3][0]);
			swap(b[1][0], b[2][1]);
			swap(b[2][0], b[1][1]);
		}
		else if(s[i]=='D')
		{
			bool t = b[0][0];
			b[0][0] = b[1][0];
			b[1][0] = b[2][0];
			b[2][0] = b[3][0];
			b[3][0] = b[3][1];
			b[3][1] = b[2][1];
			b[2][1] = b[1][1];
			b[1][1] = b[0][1];
			b[0][1] = t;	
		}
	}

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(b[i][j] == true)
			{
				cout << i+1 << " "  << j+1;
				break;
			}
		}
	}
}