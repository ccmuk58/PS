#include<bits/stdc++.h>	
using namespace std;
using ll = long long;
using pi = pair<int, int>;

class segment_tree {
private:
	vector<int> tree;

public:
	segment_tree(int N) {
		int level = ceil(log2(N));
		tree.resize(pow(2, level + 1));

	}
	void update(int start, int end, int node, const int &idx, const int &val) {
		if (start > idx || end < idx)
			return;
		if (start == end) {
			tree[node] = val;
			return;
		}
		int mid = (start + end) / 2;
		update(start, mid, node * 2, idx, val);
		update(mid + 1, end, node * 2 + 1, idx, val);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}

	int query(int start, int end, int node, const int& left, const int& right)
	{
		if (start > right || end < left) return INT32_MAX;
		if (start >= left && end <= right) return tree[node];
		int mid = (start + end) / 2;
		return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
	}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n;
	segment_tree tree(n);

	int A;
	for (int i = 1; i <= n; i++)
	{
		cin >> A;
		tree.update(1, n, 1, i, A);
	}

	cin >> m;
	int a, b, c;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			tree.update(1, n, 1, b, c);
		else if (a == 2)
			cout << tree.query(1, n, 1, b, c) << "\n";
	}

}