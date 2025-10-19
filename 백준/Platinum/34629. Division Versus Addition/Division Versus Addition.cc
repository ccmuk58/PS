#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
vector<ll> pn;
ll p(ll n)
{
	ll x = 2;
	ll res = 1;
	while(n)
	{
		if(n&1)
		{
			res *= x;
		}
		x *= x;
		n = n>>1;
	}
	return res;
}
void solve()
{
	vector<ll> v;
	cin >> N >> Q;

	ll psum[N+2] = {};
	vector<ll> idx;
	v.push_back(0);

	for(int i=1; i<=N; i++)
	{
		cin >> A;
		v.push_back(A);
		ll cnt = 0;
		if(A%2==1)
		{
			auto bb = lower_bound(pn.begin(), pn.end(), (ll)A/2);
			if(bb!=pn.end() && *bb==(ll)A/2)
			{
				idx.push_back(i);
			}
		}
		while(A>1)
		{
			A/=2;
			cnt++;
		}
		psum[i]=cnt;
		psum[i]+=psum[i-1];
		auto aa = lower_bound(pn.begin(), pn.end(), v[i]);
		if(aa!=pn.end() && *aa!=v[i])
		{
			psum[i]++;
		}
	}
/*
1
7 2
4 3 2 5 6 3 5
1 6
1 7
*/

	while(Q--)
	{
		cin >> L >>R;
		auto cc = lower_bound(idx.begin(), idx.end(), L);
		auto dd = upper_bound(idx.begin(), idx.end(), R);
		ll ee = 0;
		if(cc!=idx.end() && *cc<=R)
		{
			ee = (dd-cc+1)/2;
		}
		cout << psum[R] - psum[L-1] - ee << "\n";
	}
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin>>T;
	
	for(int i=0; i<=33; i++)
	{
		pn.push_back(p(i));
	}

	while(T--)
	{
		solve();
	}
}