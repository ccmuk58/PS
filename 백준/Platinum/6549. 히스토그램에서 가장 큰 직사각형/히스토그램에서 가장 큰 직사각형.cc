#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

pl dc(vector<ll>& h, ll l, ll r){
	if(l==r) return {h[l], h[l]};

	ll mid= (l+r)/2;
	pl maxl = dc(h, l, mid);
	pl maxr = dc(h, mid+1, r);

	ll minh = min(maxl.second, maxr.second);
	ll maxs = max(maxl.first, max(maxr.first, minh * (r-l+1)));

	ll midl = mid;
	ll midr = mid+1;
	ll minmidh = min(h[midl], h[midr]);
	maxs = max(maxs, minmidh*(midr-midl+1));

	while(!(midl==l && midr==r))
	{
		if(midl==l)
			minmidh = min(minmidh, h[++midr]);
		else if(midr == r)
			minmidh = min(minmidh, h[--midl]);
		else
		{
			if(h[midl-1] >= h[midr+1])
				minmidh = min(minmidh, h[--midl]);
			else
				minmidh = min(minmidh, h[++midr]);
		}
		maxs = max(maxs, minmidh*(midr-midl+1));
	}
	return {maxs, minh};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	while(true)
	{
		cin >> N;
		if(N==0) return 0;
		vector<ll> h(N+2);
		for(int i=1;i<=N; i++)
		{
			cin>>h[i];
		}
		cout << dc(h, 1, N).first << "\n";
	}
}