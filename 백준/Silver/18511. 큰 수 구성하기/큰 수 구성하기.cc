#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll,ll>;
using pll = pair<ll, pair<ll,ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
string ansStr;
string str;
vector<char> v;
void go(int idx)
{
	if(idx==str.length())
	{
		if(stoll(str) < stoll(ansStr))
			return;
		else
		{
			cout << ansStr;
			exit(0);
		}
	}
	for(int i=0; i<K; i++)
	{
		ansStr[idx] = v[i];
		go(idx+1);
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> str >> K;
	ll ans = 0;

	ansStr = str;
	for(int i=0; i<K; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end(), greater<char>());

	go(0);
	
	for(int i=0; i<str.length()-1; i++)
	{
		cout << v[0];
	}
}