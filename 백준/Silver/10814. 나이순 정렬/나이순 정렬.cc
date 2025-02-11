#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;

int N;
vector<pair<int, pair<int , string>>> user;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		user.push_back({age, {i, name}});
	}

	sort(user.begin(), user.end());
	for(int i=0; i<N; i++)
	{
		cout << user[i].first << " " << user[i].second.second << "\n";
	}
}