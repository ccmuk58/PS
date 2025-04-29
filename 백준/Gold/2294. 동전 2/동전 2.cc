#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int dp[100002];
vector<int> coin;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        coin.push_back(a);
    }
	fill(dp+1, dp+100001, 100002);	
	sort(coin.begin(), coin.end());
	for(int& c : coin)
	{
		int cnt=1;
		for(int i=c; i<=K; i++)
		{
			if(dp[i-c]==100002) continue;
			dp[i] = min(dp[i], dp[i-c]+1);
		}
	}

	if(dp[K]==100002)dp[K] = -1;
	cout << dp[K];


}