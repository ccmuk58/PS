#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e6 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y,
    Z;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> R >> C;

	if(N==3)
	{
		if(R==2 && C ==2)
			cout << 1;
		else
			cout << 4;
	}
	else if(N%2==0 || (R+C)%2==1)
		cout << (ll)N*N/2;
	else
		cout << (ll)N*N/2+1;
}