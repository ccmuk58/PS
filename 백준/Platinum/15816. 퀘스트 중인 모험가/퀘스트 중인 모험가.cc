#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, a, b, c, q[1111111], bit[2222222]{};
vector<ll> x, arr;
vector<tuple<ll, ll, ll>> v;

void update(ll pos, ll val) {
	while (pos <= 2111111) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

ll query(ll pos) {
	ll ret{ 0 };
	while (pos > 0) {
		ret += bit[pos];
		pos -= (pos & (-pos));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (ll i{ 0 }; i < n; i++) {
		cin >> q[i];
		arr.push_back(q[i]);
	}
	cin >> m;
	while (m--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			x.push_back(b);
			arr.push_back(b);
			v.push_back({a, b, 0});
		}
		if (a == 2) {
			cin >> b >> c;
			v.push_back({a, b, c});
		}
	}
	arr.push_back(-9e10);
	arr.push_back(9e10);
	sort(arr.begin(), arr.end());
	for (auto i : x) {
		update(lower_bound(arr.begin(), arr.end(), i) - arr.begin(), 1);
	}
	for (auto [a, b, c] : v) {
		if (a == 1) {
			update(lower_bound(arr.begin(), arr.end(), b) - arr.begin(), -1);
		}
		if (a == 2) {
			ll l = lower_bound(arr.begin(), arr.end(), b) - arr.begin();
			ll r = lower_bound(arr.begin(), arr.end(), c) - arr.begin();
			if (arr[r] != c) {
				r -= 1;
			}
			cout << (c - b + 1) - (r - l + 1) + (query(r) - query(l - 1)) << '\n';
		}
	}
}