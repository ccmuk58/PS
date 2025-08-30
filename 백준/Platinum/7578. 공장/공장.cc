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

class segtree {
public:
  int size;
  vector<ll> tree;
  segtree(int n) {
    size = 1;
    while (size < n)
      size *= 2;
    tree.assign(2 * size, 0);
  }

  void update(int i, ll x) {
    i += size;
    tree[i] += x;
    for (i /= 2; i >= 1; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }

  // [l, r)
  ll query(int l, int r) {
    ll res = 0;
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
      if (l % 2)
        res = res + tree[l++];
      if (r % 2)
        res = res + tree[--r];
    }
    return res;
  }
};


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	ll ans = 0;
	cin >> N;
	segtree sgt(N+2);

	unordered_map<ll, ll> um;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		um[A] = i+1;
	}
	
	for(int i=0; i<N; i++)
	{
		cin >> A;
		ans += sgt.query(um[A]+1, N+1);
		sgt.update(um[A], 1);
	}

	cout << ans;

}