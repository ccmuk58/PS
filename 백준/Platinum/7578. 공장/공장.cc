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

class sgtree{
	private:
	vector<ll> tree;

	public:
	sgtree(int N)
	{
		tree.resize(N*4);
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

	ll ans = 0;
	cin >> N;
	sgtree sgt(N);

	map<ll, ll> m;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		m[A] = i+1;
	}
	
	for(int i=0; i<N; i++)
	{
		cin >> A;
		ans += sgt.query(1, N, 1, m[A]+1, N);
		sgt.update(1, N, 1, m[A], 1);
	}

	cout << ans;

}