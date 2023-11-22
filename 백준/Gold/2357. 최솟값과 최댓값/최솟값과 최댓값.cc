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
		void init_min(int start, int end, int node, const vector<int> &v){
			if(start == end){
				tree[node] = v[start];
				return;
			}
			int mid = (start + end) / 2;
			init_min(start, mid, node*2, v);
			init_min(mid+1, end, node*2+1, v);
			tree[node] = min(tree[node*2], tree[node*2+1]);
		}
		
		int query_min(int start, int end, int node, const int &left, const int &right)
		{
			if(start > right || end < left) return INT32_MAX;
			if(start >= left && end <= right) return tree[node];
			int mid = (start + end) / 2;
			return min(query_min(start, mid, node*2, left, right), query_min(mid+1, end, node*2+1, left, right));
		}
		void init_max(int start, int end, int node, const vector<int> &v){
			if(start == end){
				tree[node] = v[start];
				return;
			}
			int mid = (start + end) / 2;
			init_max(start, mid, node*2, v);
			init_max(mid+1, end, node*2+1, v);
			tree[node] = max(tree[node*2], tree[node*2+1]);
		}
		int query_max(int start, int end, int node, const int &left, const int &right)
		{
			if(start > right || end < left) return 0;
			if(start >= left && end <= right) return tree[node];
			int mid = (start + end) / 2;
			return max(query_max(start, mid, node*2, left, right), query_max(mid+1, end, node*2+1, left, right));
		}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	
	vector<int> v(n+2);
	segment_tree minTree(n);
	segment_tree maxTree(n);
	
	for(int i=1 ; i<=n; i++)
		cin >> v[i];
		
	minTree.init_min(1, n, 1, v);
	maxTree.init_max(1, n, 1, v);
	
	int a,b;
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		cout << minTree.query_min(1, n, 1, a, b) << " " << maxTree.query_max(1, n, 1, a, b) << "\n";
	}

}