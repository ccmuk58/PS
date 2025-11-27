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
ll ans = 0;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> Q;

	set<int> s[N+2];
	for(int i=1; i<=N; i++)
	{
		cin >> S;
		for(int j=0; j<S; j++)
		{
			cin >> A;
			s[i].insert(A);
		}
	}

	while(Q--)
	{
		cin >> C;
		if(C==1)
		{
			cin >> A >> B;
			if(s[A].size()<s[B].size()) swap(s[A], s[B]);

			for(int x:s[B])
			{
				s[A].insert(x);
			}
			s[B].clear();
		}
		else
		{
			cin >> A;
			cout << s[A].size() << "\n";
		}
	}
}