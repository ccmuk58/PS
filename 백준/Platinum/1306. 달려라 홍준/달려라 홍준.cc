#include <bits/stdc++.h>
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
        fill(tree.begin(), tree.end(), 1);
    }
    void update(int start, int end, int node, const int &idx, const int &val) {
        if (idx < start || idx > end) return;
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, val);
        update(mid + 1, end, node * 2 + 1, idx, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int start, int end, int node, const int &left, const int &right) {
        if (start > right || end < left) return 1;
        if (start >= left && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return max(query(start, mid, node * 2, left, right),
                   query(mid + 1, end, node * 2 + 1, left, right));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    segment_tree tree(n);
    int v;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        tree.update(1, n, 1, i, v);
    }
    for (int i = m; i <= n - m + 1; i++)
        cout << tree.query(1, n, 1, i - m + 1, i + m - 1) << " ";
}