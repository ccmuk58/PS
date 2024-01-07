#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 10e5 + 2;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t, n;

	cin >> t;
	for(int i=0; i<t; i++)
	{
		cin >> n;
		if((n+1)%(n%100)==0)
		{
			cout << "Good\n";
		}
		else
			cout << "Bye\n";
	}
}