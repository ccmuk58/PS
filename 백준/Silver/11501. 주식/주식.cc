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
constexpr ll LMT = 1e9 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	

	cin >> T;

	while(T--)
	{
		cin >> N;
		ll ans = 0;

		stack<ll> s;
		while(N--)
		{
			cin >> A;
			s.push(A);
		}

		ll mx=0;
		while(!s.empty())
		{
			auto cur = s.top();
			s.pop();
			ans+=max(0ll,(mx-cur));
			mx = max(mx, cur);
		}

		cout << ans << "\n";
	}

}