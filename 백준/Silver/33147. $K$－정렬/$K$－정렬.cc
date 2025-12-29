#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> K;
	vector<ll> v;
	ll ans = 0;

	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
	}


	ll g = gcd(N, K);

	for(int i=0; i<N; i++)
	{
		if(abs(v[i]-i)%g)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}
