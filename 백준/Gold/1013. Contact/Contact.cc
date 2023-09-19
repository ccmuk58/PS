#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	regex re("(100+1+|01)+");

	int N;
	cin >> N;

	string str;
	while(N--)
	{
		cin >> str;
		if(regex_match(str, re)) cout << "YES\n";
		else cout << "NO\n";
	}
}