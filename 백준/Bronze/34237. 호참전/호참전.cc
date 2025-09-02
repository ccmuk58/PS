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

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	vector<pi> v;

	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		v.push_back({A, B});
	}

	for(int i=0; i<M; i++)
	{
		int ans = 0;
		cin >> A >> B >>C;

		for(int j=0; j<N; j++)
		{
			if(v[j].first+v[j].second<=A && v[j].first>=B && v[j].second>=C)
			{
				ans++;
			}
		}
		cout << ans << "\n";
	}


}