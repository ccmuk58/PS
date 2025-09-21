#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, c, cSum;
double g, sum;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cSum = 0;
		sum = 0;
		for (ll i{ 0 }; i < n; i++) {
			cin >> c >> g;
			cSum += c;
			sum += c * g;
		}
		cout << cSum << ' ';
		cout <<fixed << setprecision(1)<< sum / cSum << '\n';
	}
}
