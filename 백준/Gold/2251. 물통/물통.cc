#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

bool vstd[202][202][202];

queue<pll> q;
void psh(ll na,ll nb,ll nc)
{
	if(!vstd[na][nb][nc]) q.push({na,{nb,nc}});
	vstd[na][nb][nc] = true;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	set<ll> s;
	ll ans = 0;

	cin >> A >> B >> C;
	
	q.push({0,{0,C}});
	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();
		ll a = cur.first;
		ll b = cur.second.first;
		ll c = cur.second.second;
		vstd[a][b][c]=true;

		if(a==0) s.insert(c);

		// a to b
		ll na = a;
		ll nb = b;
		ll nc = c;
		ll mv = 0;
		if(b+a > B) mv = B-b;
		else mv = a;
		na=a-mv;
		nb=b+mv;
		psh(na, nb, nc);

		// a to c
		mv = 0;
		na = a;
		nb = b;
		nc = c;
		if(c+a > C) mv = C-c;
		else mv = a;
		na=a-mv;
		nc=c+mv;
		psh(na, nb, nc);

		// b to a
		mv = 0;
		na = a;
		nb = b;
		nc = c;
		if(a+b > A) mv = A-a;
		else mv = b;
		na=a+mv;
		nb=b-mv;
		psh(na, nb, nc);

		// b to c
		mv = 0;
		na = a;
		nb = b;
		nc = c;
		if(c+b > C) mv = C-c;
		else mv = b;
		nc=c+mv;
		nb=b-mv;
		psh(na, nb, nc);

		// c to b
		na = a;
		nb = b;
		nc = c;
		mv = 0;
		if(b+c > B) mv = B-b;
		else mv = c;
		nc=c-mv;
		nb=b+mv;
		psh(na, nb, nc);

		// c to a
		na = a;
		nb = b;
		nc = c;
		mv = 0;
		if(a+c > A) mv = A-a;
		else mv = c;
		nc=c-mv;
		na=a+mv;
		psh(na, nb, nc);
	}

	for(auto x : s)
	{
		cout << x << " ";
	}
}