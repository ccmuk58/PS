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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin >> N;

	if(N==1) 
		cout << 1 <<"\n";
	else 
		cout << N*2-2 << "\n";

	for(int i=1; i<=N; i++)
		cout << "1 " << i << "\n";
	for(int i=2; i<=N-1; i++)
		cout << N << " " << i << "\n";
	
}