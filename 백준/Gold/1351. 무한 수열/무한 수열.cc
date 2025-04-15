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

map<ll, ll> m;

ll dc(ll a)
{
	if(m[a]!=0) return m[a];

	return m[a] = dc(a/P) + dc(a/Q);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin >> N >> P >> Q;

	m[0] = 1;
	dc(N);
	cout << m[N];
}