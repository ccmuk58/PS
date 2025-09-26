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
ll ans = 0;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M >> K;
	vector<pl> v;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back({A, i+1});
		
	}
	sort(v.begin(), v.end());

	int freeze = M;
	ll sm = 0;
	ll needs=K-freeze;
	if(needs > N)
	{
		cout << -1;
		return 0 ;
	}
	for(int i=0; i<needs; i++)
	{
		sm+=v[i].first;
	}

	if(sm<=K)
	{
		for(int i=0; i<freeze; i++)
			cout << 0 << " ";

		for(int i=0; i<needs; i++)
		{
			cout << v[i].second << " ";
		}
	}
	else
	{
		cout << -1;
	}

}