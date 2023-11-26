#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
	
	string s1,s2;
    cin >> s1 >> s2;

	

	for(int i=1; i<=s2.size(); i++){
		for(int j=1; j<=s1.size(); j++)
		{
			if(s1[j-1] == s2[i-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[s2.size()][s1.size()];

}