#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = 0;
vector<ll> v;

ll p(ll x, ll n)
{
	ll ret = 1;

	while(n)
	{
		if(n&1)
		{
			ret*=x;
			ret%=C;
		}
		x*=x;
		x%=C;
		n= n>>1;
	}
	return ret;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> A >> B >> C;

	

	cout << p(A, B);


}