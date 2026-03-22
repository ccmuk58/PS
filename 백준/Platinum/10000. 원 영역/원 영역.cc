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
auto cmp = [](const pl& a, const pl& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	ll ans = 1;
	vector<pl> v;
	stack<pair<pl, ll>> s;

	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		v.push_back({A-B, A+B});
	}
	sort(v.begin(), v.end(), cmp);

	for(int i=0; i<N; i++)
	{
		auto cur = v[i];
		ans++;

		if(s.empty())
		{
			s.push({{cur.first, cur.second}, cur.second-cur.first});
		}
		else
		{
			ll sub_len = 0;
			while(!s.empty() && s.top().first.second <= cur.first)
			{
				sub_len = s.top().second;
				s.pop();
			}

			if(!s.empty() && sub_len + (cur.second-cur.first) == s.top().first.second - s.top().first.first)
				ans++;

			s.push({{cur.first, cur.second}, sub_len + (cur.second-cur.first)});
		}
	}

	cout << ans;
}