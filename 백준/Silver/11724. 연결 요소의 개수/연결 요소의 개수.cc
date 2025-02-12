#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int parent[1002];
int ans;

void init()
{
	for(int i=1; i<1002; i++)
	{
		parent[i] = i;
	}
}
int find(int index)
{
	if(parent[index] == index) return index;
	return find(parent[index]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b) return;
	parent[a] = b;
	ans--;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	ans = N;
	init();
	for(int i=0; i<M; i++)
	{
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
	cout << ans;

}
