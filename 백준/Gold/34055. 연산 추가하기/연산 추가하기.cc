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


int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> H;
	vector<pl> v;
	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		v.push_back({A,B});
	}
	
	if(N>0)
		sort(v.begin(), v.end());

	vector<ll> gap;
	vector<ll> pre;

	if(N==0)
	{
		gap.push_back(H);
	}
	else
	{
		ll s = v[0].first;
		ll e = v[0].second;
		gap.push_back(s-1);
		for(int i=1; i<N; i++)
		{
			if(v[i].first>e+1)
				gap.push_back(v[i].first - e - 1);
			if(e < v[i].second)
				e = v[i].second;
		}
		
		if(e<H)
		{
			gap.push_back(H-e);
		}
	}

	gap.push_back(0);
	sort(gap.begin(), gap.end());
	pre = gap;
	for(int i=1; i<pre.size(); i++)
	{
		pre[i] = pre[i] + pre[i-1];
	}

	cin >> Q;
	for(int i=0; i<Q; i++)
	{
		cin >> T;
		ll idx = lower_bound(gap.begin(), gap.end(), T) - gap.begin();
		ll ans = pre[pre.size()-1] - pre[idx-1] - (T-1)*(pre.size()-idx);
		if(ans<0) ans = 0;
		cout << ans << "\n";
	}

}