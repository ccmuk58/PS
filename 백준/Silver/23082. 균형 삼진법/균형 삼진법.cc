#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	int cnt=0;
	int n[32]={};
	bool nega=false;
	if(N==0)
	{
		cout << 0;
		return 0;
	}
	else if(N<0)
	{
		nega=true;
		N*=-1;
	}
	while(N>=3)
	{
		int m = N%3;
		N /= 3;

		n[cnt] += m;
		if(n[cnt]>=2)
		{
			n[cnt+1]+=1;
			n[cnt]-=3;
		}
		cnt++;
	}
	if(N>0)
	{
		n[cnt] += N;
		if(n[cnt]>=2)
		{
			n[cnt+1]+=1;
			n[cnt]-=3;
			cnt++;
		}
		cnt++;
	}


	for(int i=cnt-1; i>=0; i--)
	{
		if(nega==false)
		{
			if(n[i]==-1)
				cout << "T";
			else
				cout << n[i];
		}
		else
		{
			if(n[i]==1)
				cout << "T";
			else if(n[i]==-1)
				cout << 1;
			else
				cout << n[i];
		}
	}

}