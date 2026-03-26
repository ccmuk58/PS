#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >>T;

	while(T--)
	{
		cin >> N;
		ll ans =N;
		vector<pl> v;
	
		for(int i=0; i<N; i++)
		{
			cin >> A >> B;
			v.push_back({A, B});
		}
		sort(v.begin(), v.end());

		ll mn=N+2;
		for(int i=0; i<N; i++)
		{
			if(mn<v[i].second) ans--;
			else mn = v[i].second;
		}
		cout << ans << "\n";
	}


}

/*
1 5
2 2
3 1
4 4
5 3
*/