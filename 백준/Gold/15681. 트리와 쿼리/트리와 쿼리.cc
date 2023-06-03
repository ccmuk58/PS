#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 100002;

vector<int> graph[LIMIT];
int dp[LIMIT];
int query[LIMIT];
void find(int now, int pernet)
{
	dp[now] = 1;
	for (int next : graph[now])
	{
		if (next == pernet) continue;
		find(next, now);
		dp[now] += dp[next];
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int U, V;
		cin >> U >> V;
		graph[U].push_back(V);
		graph[V].push_back(U);
	}

	find(R, -1);
	for (int i = 0; i < Q; i++)
	{
		int U;
		cin >> U;
		query[i] = U;
	}
	for (int i = 0; i < Q; i++)
	{
		cout << dp[query[i]] << "\n";
	}
}