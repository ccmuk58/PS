#include <bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 1e5 + 2;
using ll = long long;
int n;
ll dp[LIMIT];
vector<ll> t;
vector<ll> b;
vector<ll> c;


int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	ll tmp;
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		t.push_back(tmp);
	}
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		b.push_back(tmp);
	}
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		c.push_back(tmp);
	}

	dp[0] = c[0];

	for(int i=1; i<n; i++)
	{
		dp[i] = c[i];
		if(t[i]-b[i]-1 >= 0)
			dp[i] += dp[lower_bound(t.begin(), t.end(), t[i]-b[i]) - t.begin() - 1];
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[n-1];
}
