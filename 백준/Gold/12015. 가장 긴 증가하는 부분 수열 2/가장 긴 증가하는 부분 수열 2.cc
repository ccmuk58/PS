#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int dp[n+1];	
	for (int i = 0; i < n; i++) cin >> v[i];
	dp[0] = v[0];
	int ans = 1;
	for(int i=1; i<n; i++)
	{
		if(v[i] > dp[ans-1])
		{
			dp[ans++]  = v[i];
		}
		else{
			*lower_bound(dp, dp+ans, v[i]) = v[i];
		}
	}
	cout << ans;
}