#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int LIMIT = 52;

int N, M, T;
int parent[LIMIT];
int party[LIMIT][LIMIT];
int ans;

void Init(int n)
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}
int Find(int n)
{
	if (parent[n] == n)return n;
	else if (parent[n] == -1) return -1;

	return parent[n] = Find(parent[n]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	else if (a > b) swap(a, b);
	parent[b] = a;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> T;
	Init(N);

	int n, p, root;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		parent[n] = -1;
	}
	
	for (int i = 0; i < M; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> p;
			party[i][j] = p;
			if (j > 0) Union(party[i][j - 1], party[i][j]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (Find(party[i][0]) != -1) ++ans;
	}
	cout << ans;
}