#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	int t, n;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		cin >> n;
		for(int j=0; j<n/5; j++)
		{
			cout <<  "++++ ";
		}
		for(int j=0; j<n%5; j++){
			cout << "|";
		}
		cout << "\n";
	}

	

}