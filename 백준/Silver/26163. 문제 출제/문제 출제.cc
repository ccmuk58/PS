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

ll a[6]={};
void go(ll lmt, ll pay, ll idx, ll cnt)
{
	if(lmt>10 && cnt>=4)
	{
		ans = max(ans, pay);
	}
	else if(lmt<=10 && cnt<=3)
	{
		ans = max(ans, pay);
	}
	for(int i=idx; i<=5; i++)
	{
		if(lmt+i <= 15)
		{
			go(lmt+i, pay+a[i], i, cnt+1);
		}
		else
			return;
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	for(int i=1; i<=5; i++)
	{
		cin >> a[i];
	}

	for(int i=1; i<=5; i++)
	{
		go(i, a[i], i, 1);
	}
	cout << ans;

}