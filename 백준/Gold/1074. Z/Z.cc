#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e3 + 2;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> R >> C;

	int ans=0;
	while(N)
	{
		int pn = pow(2, N);
		if(R+1 > pn/2)
		{
			ans += pn*pn/2;
			R-=pn/2;
		}
		if(C+1 > pn/2)
		{
			ans += pn*pn/4;
			C-=pn/2;
		}
		N--;
	}
	cout << ans;
}