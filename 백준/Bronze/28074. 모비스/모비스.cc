#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	map<char, bool> m;
	m['M'] = false;
	m['O'] = false;
	m['B'] = false;
	m['I'] = false;
	m['S'] = false;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		m[str[i]] = true;
	}
	if (m['M'] && m['O'] && m['B'] && m['I'] && m['S']) cout << "YES";
	else cout << "NO";
}