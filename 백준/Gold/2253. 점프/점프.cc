#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using pip = pair<int, pi>;
using plp = pair<ll, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e9 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    ll ans = LMT;
	unordered_map<ll, bool> isSmall;
	int dp[N+2][200] = {};
	for(int i=0; i<N+2; i++)
	{
		fill(dp[i], dp[i]+200, LMT);
	}
    for (int i = 0; i < M; i++)
    {
        cin >> A;
		isSmall[A]=true;
    }

	if(isSmall[2])
	{
		cout << -1;
		return 0;
	}

	stack<plp> q;
    // 번호, 횟수, 가속도(x)
	q.push({2, {1,1}});
	while(!q.empty())
	{
		ll num = q.top().first;
		ll cnt = q.top().second.first;
		ll acc = q.top().second.second-1;
		q.pop();
        for (int j = 0; j <= 2; j++, acc++)
        {
			ll nNum = num+acc;
			if(nNum <= N && acc>0 && !isSmall[nNum])
			{
				if(dp[nNum][acc] <= cnt+1)
				{
					continue;
				}
				if(nNum==N)
				{
					ans = min(ans, cnt+1);
					continue;
				}
				dp[nNum][acc] = cnt+1;
				q.push({nNum, {cnt+1, acc}});
			}
        }
    }
	if(ans==LMT)
	{
		cout << -1;
	}
	else
		cout << ans;
}