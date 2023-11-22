#include<bits/stdc++.h>	
using namespace std;
using ll = long long;
using pi = pair<int, int>;
constexpr ll MOD_NUM = 1e9+7;
class segment_tree{
	private:
		vector<ll> tree;

	public:
		segment_tree(int N){
			int level = ceil(log2(N));
			tree.resize(pow(2, level+1));
			fill(tree.begin(), tree.end(), 1);
		}
		void update(int start, int end, int node, const int &idx, const ll &val){
			if(idx < start || idx > end) return;
			if(start == end){
				tree[node] = val;
				return;
			}
			int mid = (start + end) / 2;
			update(start, mid, node*2, idx, val);
			update(mid+1, end, node*2+1, idx, val);
			tree[node] = (tree[node*2] * tree[node*2+1])%MOD_NUM;
		}

		ll query(int start, int end, int node, const int &left, const int &right)
		{
			if(start > right || end < left) return 1;
			if(start >= left && end <= right) return tree[node]%MOD_NUM;
			int mid = (start + end) / 2;
			return (query(start, mid, node*2, left, right) * query(mid+1, end, node*2+1, left, right))%MOD_NUM;
		}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;
	
	segment_tree tree(n);
	ll v;
	for(int i=1 ; i<=n; i++)
	{
		cin >> v;
		tree.update(1, n, 1, i, v);
	}
		
	
	ll a,b,c;
	for(int i=0; i<m+k; i++)
	{
		cin >> a >> b >> c;
		if(a==1)
			tree.update(1, n, 1, b, c);
		else if(a==2)
			cout << tree.query(1, n, 1, b, c) << "\n";
	}

}