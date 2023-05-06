#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int dp[41] = { 0, 1, 2 };
	int N, M;
	int result = 1;
	cin >> N >> M;
	for (int i = 3; i < 41; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int lastVip = 0;
	while (M--)
	{
		int vip;
		cin >> vip;
		if(vip - lastVip - 1 > 0)
			result *= dp[vip - lastVip - 1];
		lastVip = vip;
	}
	if(N != lastVip)
		result *= dp[N - lastVip];
	cout << result;
}