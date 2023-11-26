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
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string lcs;
	
	int i = s2.size();
	int j = s1.size();
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i-1][j])
			i--;
		else if(dp[i][j] == dp[i][j-1])
			j--;
		else{
			i--; j--;
			lcs += s1[j];
		}
	}

	cout << dp[s2.size()][s1.size()];
	cout << "\n";

	for(int i=lcs.length()-1; i>=0; i--)
		cout << lcs[i];
}