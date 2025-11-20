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
	
	cin >> N >> M;

	int a[N+2][2] = {};
	for(int i=0; i<M; i++)
	{
		char c;
		cin >> A >> c >> B;
		if(c=='P')
			a[A][0] = B+1;
		else
			a[A][1] = B+1;
	}

	
	int mn=0;
	int mx=0;
	for(int i=1; i<=N; i++)
	{
		if(a[i][0]==2)
		{
			if(a[i][1]==1)
			{
				mn++;
				mx++;
			}
			else if(a[i][1]==0)
			{
				mx++;
			}
		}
		else if(a[i][0]==0)
		{
			if(a[i][1]==1)
			{
				mx++;
			}
			else if(a[i][1]==0)
			{
				mx++;
			}
		}
	}

	cout << mn << " " << mx;

}