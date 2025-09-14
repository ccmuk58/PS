#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {1, -1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

double ans = 0;
bool vstd[40][40];
double per[4];

void dfs(int cnt, double prob, int y, int x)
{
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(vstd[ny][nx]) continue;
		if(prob*per[i]==0) continue;
		if(cnt+1==T)
		{
			ans+= prob*per[i];
			continue;
		}
		vstd[ny][nx] = true;
		dfs(cnt+1, prob*per[i], ny, nx);
		vstd[ny][nx] = false;
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> T >> per[0] >> per[1] >> per[2] >> per[3];


	for(int i=0; i<4; i++)
	{
		per[i] /= 100;
	}

	vstd[20][20]=true;
	dfs(0, 1, 20, 20);
	cout.precision(10);
	cout << ans;


}