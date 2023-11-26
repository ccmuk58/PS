#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
bool cmp (const pi& a, const pi& b) {
	return a.first < b.first;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<pi> v(n);
	for(auto& [x, y] : v) cin >> x >> y;

	sort(v.begin(), v.end(), cmp);

	ll total = 0;
	ll left = v[0].first;
	ll right = v[0].second;
	for(int i=1; i<n; i++)
	{
		if(v[i].first >= right) {
			total += abs(right - left);
			left = v[i].first;
			right = v[i].second;
			continue;
		}
		if(v[i].second > right) {
			right = v[i].second;
		}
	}
	total += abs(right - left);
	cout << total << '\n';
}