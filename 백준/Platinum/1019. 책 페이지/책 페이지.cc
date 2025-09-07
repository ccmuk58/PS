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

vector<ll> ans(10, 0);

void calc(int num, int point)
{
	while(num > 0)
	{
		ans[num%10] += point;
		num/=10;
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	
	ll start = 1;
	ll point = 1;

	while(start<=N)
	{
		while(start < 10 && start<=N)
		{
			calc(start, point);
			start++;
		}


		while(N%10 != 9 && start<=N)
		{
			calc(N, point);
			N--;
		}

		if(start>N) break;

		ll count = N/10 - start/10 + 1;

		for(int i=0; i<10; ++i)
		{
			ans[i]+= count * point;
		}

		start/=10;
		N/=10;
		point*=10;
	}

	for(int i=0; i<10; ++i)
	{
		cout << ans[i] << " ";
	}

}