#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	ll W, H, K;
	ll N;
	ll M;
	ll A;

	vector<ll> y;
	vector<ll> x;
	cin >> W >> H >> K;
	
	cin >> N;
	ll yend = 0;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		y.push_back(A-yend);
		yend+=y[i];
	}
	y.push_back(H-yend);

	cin >> M;
	ll xend=0;
	for(int i=0; i<M; i++)
	{
		cin >> A;
		x.push_back(A-xend);
		xend+=x[i];
	}
	x.push_back(W-xend);


	sort(y.begin(), y.end());
	sort(x.begin(), x.end());

	ll ans = 0;
	for(int i=0; i<x.size(); i++)
	{
		ll lim = K/x[i];
		ll idx = upper_bound(y.begin(), y.end(), lim) - y.begin();
		ans += idx;
	}
	cout << ans;
}