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

void go(ll sm,ll lmt, ll idx, unordered_map<ll,ll>& m, vector<ll> &v)
{
	m[sm]++;

	for(int i=idx+1; i<lmt; i++)
	{
		go(sm+v[i],lmt,i, m,v);
	}
	
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> S;
	ll ans = 0;

	vector<ll> v1;
	vector<ll> v2;
	unordered_map<ll, ll> m1;
	unordered_map<ll, ll> m2;
	for(int i=0; i<N/2; i++)
	{
		cin >> A;
		v1.push_back(A);
	}
	
	for(int i=N/2; i<N; i++)
	{
		cin >> A;
		v2.push_back(A);
	}

	for(int i=0; i<v1.size(); i++)
	{
		go(v1[i], v1.size(), i, m1,v1);
	}
	for(int i=0; i<v2.size(); i++)
	{
		go(v2[i], v2.size(), i, m2,v2);
	}

	for(const auto &it : m1)
	{
		if(it.first==S) ans+=it.second;
		ans += m2[S-it.first]*it.second;
	}

	for(const auto &it : m2)
	{
		if(it.first==S) ans+=it.second;
	}
	cout << ans;



}