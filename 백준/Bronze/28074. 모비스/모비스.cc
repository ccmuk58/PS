#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	map<char,bool> m;

	string s;
	cin >> s;

	for(int i=0; i<s.length(); i++)
	{
		m[s[i]]=true;
	}

	if(m['M']==true && m['O']==true && m['B']==true && m['I']==true && m['S']==true)
		cout << "YES";
	else
		cout << "NO";
}