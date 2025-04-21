#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll m[1048578][5][5];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while(T--)
	{
		cin >> A >> B;
		string s;
		cin >> s;
		for(int i=0; i<s.length(); i++)
		{
			char ans = (A *(s[i] - 'A') + B) % 26 + 'A';
			cout << ans;
		}
		cout << "\n";
	}
}