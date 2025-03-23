#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


// idx = cur, value = parent
int parent[LIMIT];
int level[LIMIT];
bool isPark[LIMIT];
int find(int n)
{
	if(parent[n]==n)return n;
	return parent[n] = find(parent[n]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	// if(level[a]>level[b])
	// 	swap(a, b);
	// else if(level[a]==level[b])
	// 	level[b]++;
	parent[a] = b;
	
}

int ans;
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int g;
	cin >> G >> P;
	iota(parent+1, parent+G+1, 1);
	for(int i=1; i<=G; i++) level[i] =1;
	isPark[0]=true;

	while(P--)
	{
		cin >> g;
		int pn = find(g);
		if(isPark[pn] == false)
		{
			isPark[pn] = true;
			uni(pn, pn-1);
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans;
}