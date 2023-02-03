#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

void solve()
{
	map<string, int> m{};
	map<string, int>::iterator iter;
	string clothes, type;
	int cnt = 1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> clothes >> type;
		m[type]++;
	}
	for (iter = m.begin(); iter != m.end(); iter++)
		cnt *= iter->second+1;

	cout << --cnt << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
}