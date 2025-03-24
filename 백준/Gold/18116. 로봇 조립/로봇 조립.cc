#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e6 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<int> parent(LIMIT);
int s[LIMIT];

int find(int n)
{
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a==b) return;
	if(s[a]<s[b])
	{
		swap(a, b);
	}
	parent[b] = a;
	s[a]+=s[b];
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	iota(parent.begin()+1, parent.end(), 1);
	fill(s+1, s+LIMIT, 1);
	char cmd;

	while(N--)
	{
		cin >> cmd;

		if(cmd == 'I')
		{
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}
		else
		{
			int c;
			cin >> c;
			cout << s[find(c)] << "\n";
		}
	}
}