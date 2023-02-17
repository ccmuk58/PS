#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s;

	cin >> s;
	sort(s.begin(), s.end(), greater<char>());
	cout << s;
}