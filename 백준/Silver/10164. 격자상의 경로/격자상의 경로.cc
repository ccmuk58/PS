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
	
	cin >> N >> M >> K;
	ll ans =0;

	ll m[N+2][M+2] = {};
	int ky = K/M+1;
	int kx = K%M;
	if(kx==0) {
		kx=M;
		ky--;
	}
	if(K==0) ky=N;
	if(K==0) kx=M;

	for(int i=0; i<=N; i++)
	{
		if(i>ky && 1<kx) continue;
		m[i][1] = 1;
	}	
	
	for(int j=1; j<=M; j++)
	{
		if(1<ky && j>kx) continue;
		m[1][j] = 1;
	}	

	for(int i=2; i<=N; i++)
	{
		for(int j=2; j<=M; j++)
		{
			if(i>ky && j<kx) continue;
			if(i<ky && j>kx) continue;
			m[i][j] = m[i-1][j] + m[i][j-1];
		}
	}

	cout << m[N][M];
}

// 5 5
// 8 3
// 10 5
