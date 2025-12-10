#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using plp = pair<ll, pl>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
using plpl = pair<pl, pl>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = 0;
int a[150000];
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	vector<pair<int,string>> v;
	for(int i=0; i<N; i++)
	{
		string str;
		cin >> str;
		v.push_back({str.length(), str});
	}

	sort(v.begin(), v.end(), greater<>());

	for(int i=1; i<N; i++)
	{
		if(v[0]!=v[i])
		{
			cout << v[i].second;
			return 0;
		}
	}
	
}