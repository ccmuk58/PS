#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,count=0, dp[1000000+2]={0, 0};
	cin >> n;
	
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + 1;
		if(i%2==0)
			if(dp[i/2]+1 < dp[i]) dp[i] = dp[i/2]+1;
		if(i%3==0)
			if(dp[i/3]+1 < dp[i]) dp[i] = dp[i/3]+1;
	}
	cout << dp[n] << "\n";
}