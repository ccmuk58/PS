#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1 +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

map<pl, ll> m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	ll ans=0;
	const ll c = 1000000000;
	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		if(A==0 || B==0)
		{
			ll a=1;
			a = max(a, abs(A));
			a = max(a, abs(B));
			A/=a;
			B/=a;
		}
		else
		{
			ll g = gcd(abs(A), abs(B));
			A/=g;
			B/=g;
		}
		if(A==0 && B==0)
		{
			ans += i;
		}
		else
		{
			ans+=m[{c-B,c+A}];
			ans+=m[{c+B,c-A}];
			ans+=m[{c, c}];
		}
		m[{c+A, c+B}]++;
	}
	
	cout << ans;
}