#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set oSet;

int main(){

	int n, k;
	cin >> n >> k;

	for(int i=1; i<=n; i++){
		oSet.insert(i);
	}
	cout << "<";
	int cur=0;
	for(int i=0; i<n; i++){
		cur = (cur+k-1)%(n-i);
		cout << *oSet.find_by_order(cur);
		if(i < n-1) cout << ", ";
		oSet.erase(oSet.find_by_order(cur));
	}
	cout << ">";
}