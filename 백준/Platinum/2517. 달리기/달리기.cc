#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set oSet;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, t;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> t;
		oSet.insert(t);
		cout << (i - oSet.order_of_key(t)) << " ";
	}
}