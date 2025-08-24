#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1 +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int cnt = 0;
vector<int> v[100002];
int outdegree[100002];

map<pi,int> m;
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	for(int i=0; i<M; i++)
	{
		cin >> A>> B;
		outdegree[A]++;
	}

	int ans = 0;
	for(int i=1; i<=N; i++)
	{
		if(outdegree[i]<2)
		{
			ans+= 2-outdegree[i];
		}
	}

	ans -= 2;
	cout << ans;

}
