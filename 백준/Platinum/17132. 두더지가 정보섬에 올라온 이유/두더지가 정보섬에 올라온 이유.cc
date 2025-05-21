#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int p[100002];
ll siz[100002];
ll ans;
int find(int a)
{
	if(p[a]==a) return a;
	return p[a] = find(p[a]);
}

void uni(int a, int b, int w)
{
	a = find(a);
	b = find(b);

	ans+=siz[a]*siz[b]*w;
	p[b] = a;
	siz[a]+=siz[b];
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	
	cin >> N;
	iota(p+1, p+1+N, 1);
	fill(siz+1, siz+1+N, 1);

	vector<pip> v;
	for(int i=0; i<N-1; i++)
	{
		cin >> X >> Y >> W;

		v.push_back({W,{X,Y}});
	}
	sort(v.begin(), v.end(), greater<>());

	for(int i=0; i<N-1; i++)
	{
		uni(v[i].second.first, v[i].second.second, v[i].first);
	}

	cout << ans;

}