#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e4 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int k;
int parent[LIMIT];
int cost[LIMIT];
bool isF[LIMIT];
int ans;

int find(int n)
{
	if(parent[n] == n)return n;

	return parent[n] = find(parent[n]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	parent[a] = b;
	if(cost[b] > cost[a]) cost[b] = cost[a];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> k;

	for(int i=1; i<=N; i++)
		cin >> cost[i];
		
	iota(parent+1, parent+N+1, 1);

	for(int i=0; i<M; i++)
	{
		int v, w;
		cin >> v >> w;
		
		uni(v, w);
	}

	for(int i=1; i<=N; i++)
	{
		if(isF[find(i)])continue;

		isF[find(i)] = true;
		ans += cost[find(i)];
		if(ans>k)
		{
			cout << "Oh no";
			return 0;
		}
	}

	cout << ans;
}