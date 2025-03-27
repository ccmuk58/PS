#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e4 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<int> nxt[LMT] = {};
int indegree[LMT];
int dp[LMT];
int cost[LMT];
int ans;

void solve()
{
	queue<int> q;
	for(int i=1; i<=N; i++)
	{
		dp[i]=cost[i];
		ans=max(ans , dp[i]);
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for(const auto& n : nxt[cur])
		{
			indegree[n]--;
			dp[n] = max(dp[n], dp[cur]+cost[n]);
			ans=max(ans , dp[n]);
			if(indegree[n] == 0)
				q.push(n);
		}
	}
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for(int i=1; i<=N; i++)
	{
		int out;
		cin >> cost[i] >> out;
		for(int j=0; j<out; j++)
		{
			int n;
			cin >> n;
			nxt[n].push_back(i);
			indegree[i]++;
		}
	}

	solve();
	cout << ans;
}