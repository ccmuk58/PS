#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	regex re("(100+1+|01)+");
	string str;
	cin >> str;
	if(regex_match(str, re)) cout << "SUBMARINE";
	else cout << "NOISE";
}