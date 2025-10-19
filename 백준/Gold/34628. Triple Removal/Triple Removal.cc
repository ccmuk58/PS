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

void solve()
{
	vector<ll> v;
	cin >> N >> Q;
	ll psum[N+2] = {};
	vector<ll> lst;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);

		if(A==0)
			psum[i]+=1;

		if(i>0)
		{
			psum[i] += psum[i-1];
		}
	}
	
	int last = v[0];
	for(int i=1; i<N; i++)
	{
		if(last==v[i])
		{
			lst.push_back(i-1);
		}
		last = v[i];
	}
	while(Q--)
	{
		cin >> L >> R;

		L--;
		R--;
		if((R-L+1)%3 != 0)
		{
			cout << -1 << "\n";
			continue;
		}
		if(L==0)
		{
			if((psum[R])%3!=0)
			{
				cout << -1 << "\n";
				continue;
			}
		}
		else if((psum[R] - psum[L-1])%3 != 0)
		{
			cout << -1 << "\n";
			continue;
		}
		auto aa = lower_bound(lst.begin(), lst.end(), L);

		if(aa!=lst.end() &&  *aa < R)
		{
			cout << (R-L+1)/3 << "\n";
		}
		else
		{
			cout << (R-L+1)/3+1 << "\n";
		}
	}
}

/*
1
9 1
1 0 1 0 1 0 1 1 0
1 6
*/

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin>>T;
	
	while(T--)
	{
		solve();
	}
}