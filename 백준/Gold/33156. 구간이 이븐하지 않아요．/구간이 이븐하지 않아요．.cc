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
	
	cin >> N;
	set<ll> s;
	map<ll,ll> df;
	vector<ll> v;
	ll ans = 0;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
		s.insert(A);
	}
	ll q = 0;
	for(auto &x : s)
	{
		df[x]=q;
		q++;
	}
	for(int i=0; i<N; i++)
	{
		v[i] = df[v[i]];
	}
	for(int i=0; i<N-1; i++)
	{
		ll l=i;
		ll r=i+1;
		ll len = 0;
		ll m[5000] = {};
		ll dif=0;
		while(l>=0 && r<N)
		{
			len++;
			if(m[v[l]]==0)
				dif++;
			else if(m[v[l]]==1)
				dif--;
			m[v[l]]--;

			if(m[v[r]]==0)
				dif++;
			else if(m[v[r]]==-1)
				dif--;
			m[v[r]]++;
			if(dif==0)
			{
				ans=max(ans, len*2);
			}

			l--;
			r++;
		}
		
	}

	cout << ans;
}