#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;

ll N, P;
ll ans = 1;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> P;
	for(ll i = N; i > 0; i--)
	{
		ans *= i;
		ans %= P;
	}
	cout << ans;
}
