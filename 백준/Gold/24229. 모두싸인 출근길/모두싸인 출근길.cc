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

ll ans = 0;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> N;

	vector<pi> v;
	for(int i=0; i<N; ++i)
	{
		cin >> L >> R;
		v.push_back({L, R});
	}
	sort(v.begin(), v.end());


	vector<pi> pan;
	
	int l=0;
	int r=v[0].second;

	for(int i=1; i<N; i++)
	{
		if(v[i].first<=r)
		{
			r = max(r, v[i].second);
		}
		else
		{
			pan.push_back({l, r});
			l = v[i].first;
			r = v[i].second;
		}
	}
	pan.push_back({l, r});
	l=0;
	r=pan[0].second;
	int lmt=r+r;

	int mxR = r;
	for(int i=1; i<pan.size(); i++)
	{
		if(lmt < pan[i].first) break;

		if(lmt >= pan[i].first)
		{
			mxR = pan[i].second;
		}

		if(lmt < pan[i].second + (pan[i].second-pan[i].first))
		{
			lmt = pan[i].second + (pan[i].second-pan[i].first);
		}
	}
	cout << mxR;
}