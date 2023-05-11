#include<iostream>
#include<algorithm>
using namespace std;
long long dp[31][31];

long long GetCount(int w, int h)
{
	if(w<0 || h<0) return 0;
	if(dp[w][h]!=0) return dp[w][h];
	dp[w][h] = GetCount(w-1, h+1) + GetCount(w, h-1);
	return dp[w][h];
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	for(int i=1; i<31; i++)
		dp[0][i] = 1;
	GetCount(30,0);

	while(true)
	{
		cin >> N;
		if(N==0) break;
		cout << dp[N][0] << "\n";
	}
}