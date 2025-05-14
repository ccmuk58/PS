#include<bits/stdc++.h>
using namespace std;

int A,B,C,N,M,K,L;
int main(){
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;

	int r = 0;
	int b = 0;
	int g = 0;
	for(int i=0; i<10; i++)
	{
		if(s[i]=='@')
			r=i;
		else if(s[i]=='#')
			b=i;
		else if(s[i]=='!')
			g=i;
	}

	if((g>r&&g<b )||(g<r && g>b)||(g<r && r<b)||(g>r&&r>b))
	{
		cout << -1;
	}
	else if(r>b)
	{
		cout << r-g-1;
	}
	else
	{
		cout << g-r-1;
	}

}