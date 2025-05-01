#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int p[LMT+2];
bool vstd[LMT+2][2];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;

	fill(p, p+LMT+2, -1);
	int cnt = 0;
	for(int i=K; i<=LMT; i+=cnt)
	{
		p[i] = cnt++;
	}
	int ans = INT32_MAX;
	queue<pi> q;

	q.push({N, 0});
	vstd[N][0] = true;
	while(!q.empty())
	{
		auto [cur, t] = q.front();
		q.pop();
		if(p[cur]>=t && t%2==p[cur]%2 && cur<=LMT)
		{
			ans=min(ans,p[cur]);
		}

		int nxt[3] = {cur-1, cur+1, cur*2};
		for(int i=0; i<3; i++)
		{
			if(nxt[i] <= LMT && nxt[i]>=0 && vstd[nxt[i]][(t+1)%2]==false )
			{
				q.push({nxt[i], t+1});
				vstd[nxt[i]][(t+1)%2]=true;
			}
		}
	}

	if(ans==INT32_MAX)ans=-1;
	cout << ans;
}