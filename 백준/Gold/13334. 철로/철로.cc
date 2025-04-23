#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int ans = 0;
vector<pl> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> H >> O;
		if(H>O) swap(H, O);
		v.push_back({O, H});
	}
	cin >> D;

	sort(v.begin(), v.end());

	priority_queue<int> pq;
	int i=0;
	while(i<N)
	{
		auto st = v[i].second;
		auto end = v[i].first;
		if(st >= end-D)
			pq.push(-st);

		while(!pq.empty())
		{
			if(-pq.top() >= end - D)
				break;
			pq.pop();
			
		}
		ans = max(ans, (int)pq.size());
		i++;
	}
	cout << ans;
}