#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	vector<int> v;

	cin >> n;
	for(int i=0; i<n; i++)
	{
		int s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	cout << v[n-1]+n-1;
}