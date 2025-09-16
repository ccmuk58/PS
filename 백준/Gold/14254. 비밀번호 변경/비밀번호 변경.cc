#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = 0;
vector<ll> v;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	

	string s;

	cin >> s;
	cin >> N;

	if(s.length() == N)
	{
		cout << 0;
		return 0;
	}
	int gap = s.length()-N;
	for(int i=0; i<gap; i++)
	{
		map<char, int> m;
		int mx=0;
		for(int j=i; j<s.length(); j+=gap)
		{
			m[s[j]]++;
			mx = max(mx, m[s[j]]);
		}
		N-=mx-1;
	}

	cout << N;
	

}