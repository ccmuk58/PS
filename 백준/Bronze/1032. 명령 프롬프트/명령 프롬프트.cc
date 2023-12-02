#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;

	for(int i=1; i<n; i++)
	{
		string s;
		cin >> s;
		for(int j=0; j<str.size(); j++)
		{
			if(s[j] != str[j])
				str[j] = '?';
		}
	}
	cout << str;
}