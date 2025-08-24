#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1 +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


int indegree[200002] = {};
int dp[200002] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	vector<int> v[N+2];

	for(int i=0; i<M; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}

	stack<pi> s;

	for(int i=1; i<=N; i++)
	{
		if(indegree[i]==0){
			s.push({i, 1});
			dp[i] = 1;
		}
	}

	while(!s.empty())
	{
		auto cur = s.top();
		s.pop();
		
		for(int i=0; i<v[cur.first].size(); i++)
		{
			if(dp[v[cur.first][i]]<cur.second+1)
			{
				s.push({v[cur.first][i], cur.second+1});
				dp[v[cur.first][i]]=cur.second+1;
			}
		}
	}
	int ans = 1;
	for(int i=1; i<=N; i++)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans;

}