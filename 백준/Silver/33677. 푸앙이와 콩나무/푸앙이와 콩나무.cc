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
	
	cin >> N;
	pl dp[N+2] = {};


	queue<pll> q;
	ll ansd=INT64_MAX;
	ll answ=INT64_MAX;
	q.push({0, {0, 0}});
	ll vstd[N+2] = {};
	fill(vstd, vstd+N+2, INT64_MAX);
	vstd[0]=true;
	while(!q.empty())
	{
		auto len = q.front().first;
		auto water = q.front().second.first;
		auto d = q.front().second.second;
		q.pop();
		if(d>ansd)
		{
			break;
		}
		if(len==N)
		{
			if(ansd>d)
			{
				ansd = d;
				answ = water;
			}
			else if(ansd==d && answ>water)
			{
				answ = water;
			}
			continue;
		}
		if(len+1<=N && vstd[len+1]>water+1)
		{
			q.push({len+1,{ water+1, d+1}});
			vstd[len+1]=water+1;
		}
		if( len*3<=N && vstd[len*3]>water+3)
		{
			q.push({len*3,{ water+3, d+1}});
			vstd[len*3]=water+3;
		}
		if(len*len <= N && vstd[len*len]>water+5)
		{
			q.push({len*len,{ water+5, d+1}});
			vstd[len*len]=water+5;
		}
	}

	cout << ansd << " "  << answ;

	
}