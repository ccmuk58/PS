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
  vector<int> tree;
  segtree(int n) {
    for (size = 1; size < n; size <<= 1)
      ;
    tree.resize(size * 2);
  }
  void update(int pos, int val) {
    pos += size - 1;
    tree[pos] += val;
    for (pos /= 2; pos; pos /= 2) {
      tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
  }
  int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
      return 0;
    if (l <= s && e <= r)
      return tree[n];
    int m = (s + e) >> 1;
    return query(n * 2, s, m, l, r) + query(n * 2 + 1, m + 1, e, l, r);
  }
  int query(int l, int r) { return query(1, 1, size, l, r); }
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;

	while(T--)
	{
		cin >> N >> M;
		map<ll, ll> m;
		segtree sgt(N+M+2);
		for(int i=1; i<=N; i++)
		{
			sgt.update(i, 1);
			m[N-i+1]=i;
		}
		int idx=N+1;
		for(int i=0; i<M; i++)
		{
			cin >> A;
			cout << sgt.query(m[A]+1, idx) << " ";
			sgt.update(m[A], -1);
			sgt.update(idx, 1);
			m[A] = idx;
			idx++;
		}
		cout << "\n";
	}

}