#include<iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 1000002;

int parent[LIMIT];
int level[LIMIT];

void Init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
}
int Find(int n)
{
	if (parent[n] == n) return n;

	return parent[n] = Find(parent[n]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (level[a] > level[b])
		swap(a, b);
	else if (level[a] == level[b])
		level[b]++;

	parent[a] = b;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	int cmd, a, b;
	string ans;

	cin >> n >> m;
	Init(n);

	for (int i = 0; i < m; i++)
	{
		cin >> cmd >> a >> b;
		if (cmd == 0) Union(a, b);
		else {
			ans = (Find(a) == Find(b)) ? "YES\n" : "NO\n";
			cout << ans;
		}
	}
}