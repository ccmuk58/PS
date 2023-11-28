#include <bits/stdc++.h>
using namespace std;
constexpr int LIM = 5e5 + 2;
int parent[LIM];

int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	parent[b] = a;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < LIM; i++)
		parent[i] = i;

	int n, m;
	cin >> n >> m;

	for(int i=1; i<=m; i++)
	{
		int a, b;
		cin >> a >> b;
		if(Find(a) == Find(b))
		{
			cout << i;
			return 0;
		}
		Union(a, b);
	}
	cout << 0;
}