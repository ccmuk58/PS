#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, l{ 0 }, r{ (ll)1e10 }, arr[1111111];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (ll i{ 0 }; i < n; i++) {
		cin >> arr[i];
	}
	while (l + 1 < r) {
		ll mid{ (l + r) / 2 };
		ll sum{ 0 };
		for (ll i{ 0 }; i < n; i++) {
			sum += max(mid - arr[i], 0LL);
		}
		if (sum <= k) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l;
}
