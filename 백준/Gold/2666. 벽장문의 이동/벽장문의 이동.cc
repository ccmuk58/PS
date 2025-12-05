#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using plp = pair<ll, pl>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
using plpl = pair<pl, pl>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = INT64_MAX;
int a[150000];
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	cin >> Q >> W;
	cin >> E;

	vector<int> v;
	for(int i=0; i<E; i++)
	{
		cin >> A;
		v.push_back(A);
	}

	// idx, sum, l, r
	queue<plpl> q;
	if(Q>W)swap(Q,W);
	q.push({{0, 0},{Q, W}});
	while(!q.empty())
	{
		ll idx = q.front().first.first;
		ll sum = q.front().first.second;
		ll l = q.front().second.first;
		ll r = q.front().second.second;
		q.pop();
		if(idx==E) {
			ans = min(ans, sum);
			continue;
		}
		if(v[idx] < l)
		{
			q.push({{idx+1,sum+abs(l-v[idx])},{v[idx],r}});
		}
		else if(v[idx] > r)
		{
			q.push({{idx+1,sum+abs(v[idx]-r)},{l,v[idx]}});
		}
		else
		{
			q.push({{idx+1,sum+(v[idx]-l)},{v[idx],r}});
			q.push({{idx+1,sum+(r-v[idx])},{l,v[idx]}});
		}
	}

	cout << ans;
	
}