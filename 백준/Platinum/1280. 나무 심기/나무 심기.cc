#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1 +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 200000;
constexpr ll MOD = 1000000007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

class sgtree{
	private:
	vector<ll> tree;

	public:
	sgtree(int N)
	{
		tree.resize(N*4);
		init(1, N, 1, tree);
	}
	void init(int s, int e, int node, vector<ll>& v)
	{
		if(s == e){
			tree[node] = 0;
			return;
		}
		int mid = (s + e) / 2;
		init(s, mid, node*2, v);
		init(mid+1, e, node*2+1, v);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
	// idx번째 원소를 val로 바꿨을 때 [s, e] node를 업데이트 하는 함수
	void update(int s, int e, int node, int idx, int val)
	{
        if (idx < s || idx > e)
            return;
        if (s == e)
        {
            tree[node] += val;
            return;
        }
        int mid = (s + e) / 2;
        update(s, mid, node * 2,idx ,val);
        update(mid + 1, e, node * 2 + 1,idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
	// [s, e] node를 보고 있을 때, [l, r]구간의 연산 값을 구하는 함수
	ll query(int s, int e, int node, int l, int r)
	{
		if(s > r || e < l) return 0;
		if(s >= l && e <= r) return tree[node];
		int mid = (s + e) / 2;
		return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
	}
};


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	ll ans = 1;
	cin >> N;
	sgtree sgt_sum(LMT+1);
	sgtree sgt_cnt(LMT+1);
	map<ll, ll> m;

	for(int i=0; i<N; i++)
	{
		cin >> A;
		A=A+1;
		m[A]++;
		sgt_sum.update(1, LMT, 1, A, A);
		sgt_cnt.update(1, LMT, 1, A, 1);
		ll low = sgt_cnt.query(1, LMT, 1, 1, A-1)*A - sgt_sum.query(1, LMT, 1, 1, A-1) % MOD;
		ll high = abs(sgt_cnt.query(1, LMT, 1, A+1, LMT)*A - sgt_sum.query(1, LMT, 1, A+1, LMT)) % MOD;
		ll t = low%MOD+high%MOD;
		t = max((ll)1, t);
		ans*=t;
		ans%=MOD;
	}
	if(m[A]==N) ans = 0;
	

	cout << ans;

}