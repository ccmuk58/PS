#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = unsigned long long;
using pl = pair<ll, ll>;
constexpr ll LIMIT = 1e7 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll prime[LIMIT];
ll ans;
constexpr bool MulOverflow(const ll& a, const ll& b) {
	return b && a > ll(-1) / b;
}
ll powll(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n % 2) res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> A >> B;
    for (ll i = 2; i < LIMIT; i++) prime[i] = i;

    for (ll i = 2; i < LIMIT; i++) {
        if (prime[i] == 0) continue;
        for (ll j = i * 2; j < LIMIT; j += i) {
            prime[j] = 0;
        }
    }

    for (ll i = 2; i < LIMIT; i++) {
        ll u = prime[i];
        if (u == 0) continue;
        ll p = 2;
        ll pn = powll(u, p);
        while (pn <= B) {
            if (pn >= A) ans++;
			if(MulOverflow(pn, u)) break;
            pn = powll(u, ++p);
        }
    }
    cout << ans;
}