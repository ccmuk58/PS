#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int main() {
    cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v(n);
	int dp[n+1];	
	pi track[n+1];

	for (int i = 0; i < n; i++) cin >> v[i];
	dp[0] = v[0];
	track[0] = {v[0], 0};
	int ans = 1;
	for(int i=1; i<n; i++)
	{
		if(v[i] > dp[ans-1])
		{
			track[i] = {v[i],ans};
			dp[ans++]  = v[i];
		}
		else{
			int idx = lower_bound(dp, dp+ans, v[i]) - dp;
			dp[idx] = v[i];
			track[i] = {v[i],idx};
		}
	}
	
	vector<int> lis;
	int idx = ans-1;
	for(int i=n-1; i>=0;i--)
	{
		if(track[i].second == idx)
		{
			lis.push_back(track[i].first);
			idx--;
		}
	}

	cout << ans << "\n";
	for(int i=lis.size()-1; i>=0; i--)
		cout << lis[i] << " ";
}