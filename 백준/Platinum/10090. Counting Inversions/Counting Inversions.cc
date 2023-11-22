#include<bits/stdc++.h>	
using namespace std;
using ll = long long;
using pi = pair<int, int>;

class segment_tree{
	private:
		vector<int> tree;

	public:
		segment_tree(int N){
			int level = ceil(log2(N));
			tree.resize(pow(2, level+1));
		}
		void update(int start, int end, int node, const int &val){
			if(val < start || val > end) return;
			if(start == end){
				tree[node]++;
				return;
			}
			int mid = (start + end) / 2;
			update(start, mid, node*2, val);
			update(mid+1, end, node*2+1, val);
			tree[node] = tree[node*2] + tree[node*2+1];
		}

		int query(int start, int end, int node, const int &left, const int &right)
		{
			if(start > right || end < left) return 0;
			if(start >= left && end <= right) return tree[node];
			int mid = (start + end) / 2;
			return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
		}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll result = 0;
	cin >> n;
	
	segment_tree tree(n);
	int a;
	for(int i=1 ; i<=n; i++)
	{
		cin >> a;
		tree.update(1, n, 1, a);
		result += tree.query(1, n, 1, a+1, n);
	}
	cout << result;
}