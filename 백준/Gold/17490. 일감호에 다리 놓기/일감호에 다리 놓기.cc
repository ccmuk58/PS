#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e6 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int parent[LIMIT];
int s[LIMIT];
int cost[LIMIT];
vector<int> block[LIMIT];
ll ans;

int find(int n)
{
	if(n==parent[n]) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a==b) return;
	if(s[a]>s[b]) swap(a, b);

	parent[a] = b;
	s[b] += s[a];
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	iota(parent+1, parent+LIMIT, 1);
	fill(s+1, s+LIMIT, 1);
	cin >> N >> M >> K;
	priority_queue<pair<int ,pi>, vector<pair<int,pi>>, greater<pair<int,pi>>> pq;
	
	for(int i=1; i<=N; i++)
	{
		cin >> cost[i];
		pq.push({cost[i], {i, 0}});
	}
	block[1].push_back(N);
	block[1].push_back(2);
	block[N].push_back(N-1);
	block[N].push_back(1);

	for(int i=2; i<N; i++)
	{
		block[i].push_back(i-1);
		block[i].push_back(i+1);
	}

	for(int i=0; i<M; i++)
	{
		int a, b;
		cin >> a >> b;

		if(a>b) swap(a,b);
		if(a==1 && b==N)
		{
			block[b].pop_back();
			block[a].erase(block[a].begin());
			continue;
		}
		block[a].pop_back();
		block[b].erase(block[b].begin());
	}
	
	for(int i=1; i<=N; i++)
	{
		for(const auto &a : block[i])
		{
			pq.push({0, {i, a}});
		}
	}

	while(!pq.empty())
	{
		pair<int , pi> cur = pq.top();
		pq.pop();

		if(ans>K)
		{
			cout << "NO";
			return 0;
		}
		if(s[find(1)]==N)
		{
			cout << "YES";
			return 0;
		}

		if(find(cur.second.first) == find(cur.second.second)) continue;
		uni(find(cur.second.first), find(cur.second.second));
		ans += cur.first;
	}
	if(ans>K)
	{
		cout << "NO";
		return 0;
	}
	if(s[find(1)]==N)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";

}