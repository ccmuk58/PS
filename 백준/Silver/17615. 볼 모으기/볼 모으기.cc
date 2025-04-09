#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};

constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int r1, r2, b1,b2;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	char c[500002];
	for(int i=0; i<N; i++)
	{
		cin >> c[i];
		if(c[i]=='R')
			R++;
		else
			B++;
	}
	
	int l = 1;
	while(c[0]==c[l])
	{
		if(c[0]=='R')
			r1++;
		else
			b1++;
		l++;
	}
	int r = 1;
	while(c[N-1]==c[N-r])
	{
		if(c[N-1]=='R')
			r2++;
		else
			b2++;
		r++;
	}
	int sideR = max(r1, r2);
	int sideB = max(b1, b2);

	R-=sideR;
	B-=sideB;
	cout << min(R,B);

}