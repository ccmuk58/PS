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


void calc(ll num, ll point, vector<ll> &ans)
{
	while(num>0)
	{
		ans[num%10] += point;
		num/=10;
	}
}
ll digitdp(ll num)
{
	ll point = 1;
	ll start = 1;
	ll end = num;
	vector<ll> ans(10, 0);

	while(start<=end)
	{
		while(start < 10 && start<=end)
		{
			calc(start, point, ans);
			++start;
		}
		while(end%10 != 9 && start<=end)
		{
			calc(end, point, ans);
			--end;
		}

		if(start>end) break;

		ll count = end/10;

		for(int i=0; i<10; ++i)
		{
			ans[i] += count * point;
		}

		start = 1;
		end /= 10;
		point *= 10;
	}

	ll rv = 0;
	for(int i=1; i<10; ++i)
	{
		rv+= i*ans[i];
	}
	return rv;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> L >> U;

	
	ll ans = digitdp(U)-digitdp(L-1);

	cout << ans;
}