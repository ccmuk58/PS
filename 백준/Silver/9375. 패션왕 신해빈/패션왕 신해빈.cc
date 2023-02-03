#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

void solve()
{
	map<string, int> m{};
	vector<string> v{};
	string clothes, type;
	int cnt = 1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> clothes >> type;
		m[type]++;
		bool isHas = false;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == type)
			{
				isHas = true;
				break;
			}
		}
		if (!isHas || v.size() == 0) v.push_back(type);
	}
	for (int i = 0; i < v.size(); i++)
		cnt *= m[v[i]]+1;

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