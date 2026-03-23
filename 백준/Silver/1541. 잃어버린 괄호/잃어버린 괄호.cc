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
string str;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> str;
	vector<ll> v;
	ll ans = 0;

	int firstSub = 10000;
	vector<int> op;
	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='+' || str[i]=='-') op.push_back(i);
		if(firstSub==10000 && str[i]=='-') firstSub = i;
	}
	int l = -1;
	int r = 0;
	for(int i=0; i<op.size(); i++)
	{
		r=op[i];
		int a = stoi(str.substr(l+1, r-l-1));
		if(op[i] > firstSub) ans-=a;
		else ans+=a;
		l=r;
	}
	r=str.size();
	int a = stoi(str.substr(l+1, r-l-1));
	if(str.size() > firstSub) ans-=a;
	else ans+=a;

	cout << ans;


}