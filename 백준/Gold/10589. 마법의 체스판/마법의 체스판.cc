#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;

	if(N==1&&M==1)
	{
		cout << 0;
		return 0;
	}
	int cnt = N/2 + M/2;
	cout << cnt << "\n";
	for(int i=2; i<=N; i+=2)
	{
		cout << i << " " << 1 << " " << i << " " <<  M << "\n";
	}
	
	for(int i=2; i<=M; i+=2)
	{
		cout << 1 << " " << i << " " << N << " " << i << "\n";
	}
}