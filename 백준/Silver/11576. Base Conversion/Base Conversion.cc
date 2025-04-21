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
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll m[1048578][5][5];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> A >> B;

	ll n;
	cin >> n;


	vector<ll> v;
	ll t = 0;
	for(int i=n-1; i>=0; i--)
	{
		ll a;
		cin >> a;
		t += a*pow(A, i);
	}
	
		
		while(t)
		{
			int q = t%B;
			t/=B;
			v.push_back(q);
		}
		for(int i=v.size()-1; i>=0; i--)
		{
			cout << v[i] << " ";
		}

	
}