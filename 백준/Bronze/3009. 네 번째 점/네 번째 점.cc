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
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	map<int, int> xm;
	map<int, int> ym;
	for(int i=0; i<3; i++)
	{
		cin >> A >> B;
		xm[A]++;
		ym[B]++;
	}
	int x = 0;
	int xc = 10;
	int y = 0;
	int yc = 10;
	for(auto t : xm)
	{
		if(t.second < xc)
		{
			xc=t.second;
			x=t.first;
		}
	}
	for(auto t : ym)
	{
		if(t.second < yc)
		{
			yc=t.second;
			y=t.first;
		}
	}
	cout << x << " " << y;
	

}