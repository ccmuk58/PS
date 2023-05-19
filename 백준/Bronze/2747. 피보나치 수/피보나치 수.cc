#include<iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 50;
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	int dp[LIMIT] = {0, 1};
	for(int i=2; i<LIMIT; i++)
		dp[i]= dp[i-1] + dp[i-2];
	
	cout << dp[n];
}