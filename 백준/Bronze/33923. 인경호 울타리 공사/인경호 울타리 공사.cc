#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using ll = long long;
int A,B,C,D,E,N,M,K,W,X,Y,Z;

int dis(pi a, pi b)
{
	return sqrt(pow(b.first- a.first, 2) + pow(b.second- a.second, 2));
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;

	if(N!=M)
	{
		int a = min(N,M);

		cout << (a-1)*(a-1);
		return 0;
	}
	else{
		cout << (N-2)*(N-2)+1;
		return 0;
	}
}