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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    while (T--)
    {
		ll ans = 0;
        cin >> A >> B;

		while(A!=B)
		{
			A=(A+1)/2;
			B=B/2;
		}

		while(A>1)
		{
			if(A%2==1)ans++;
			A=(A+1)/2;
		}
		cout << ans << "\n";
    }
}