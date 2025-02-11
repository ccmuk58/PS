#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

unordered_map<string, int> m;
vector<string> v;
int cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	string name;
	while(N--)
	{
		cin >> name;
		m[name] = 1;
	}
	while(M--)
	{
		cin >> name;
		if(m.find(name)!=m.end())
		{
			v.push_back(name);
			cnt++;
		}
	}
	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for(const auto &a : v)
		cout << a << "\n";
}
