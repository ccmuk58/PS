#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1 +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<ll> v;
ll get(ll n)
{
	ll t = 0;
	for(int mask = 1; mask < (1<<N); mask++)
	{
		ll m = n;
		for(int i=0; i<v.size(); i++)
		{
			if(mask >> i & 1)
			{
				m /= v[i];
			}
		}
		t += m*(__builtin_parity(mask) ? 1 : -1);
	}
	return t;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	ll ans = get(M);

	cout << ans;
}