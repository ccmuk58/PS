#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
constexpr int RANGE = 302;

int GetMaxDP(int* dp) {
	int max = (dp[1] > dp[2]) ? dp[1] : dp[2];
	return max;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 최대 값을 기억할 변수
	int dp[RANGE][3] = { 0 };
	int stair[RANGE] = { 0 };
	int n = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> stair[i];

	// int a = max(0, 1);
	
	// 초기값
	dp[1][1] = stair[1];
	for (int i = 2; i <= n; i++)
	{
		// 1회 연속 이동의 경우, -2계단의 이동 값 중 큰 값을 더함
		dp[i][1] = GetMaxDP(dp[i - 2]) + stair[i];
		// 2회 연속 이동의 경우, -1계단의 1회 연속 이동 값을 더함
		dp[i][2] = dp[i - 1][1] + stair[i];
	}

	cout << GetMaxDP(dp[n]);
}