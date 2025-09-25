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

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	

	while(true)
	{
		cin >> N ;
		if(N==0) break;
		cin >> P;
		vector<int> v;
		v.push_back(N-P+1);
		if(P%2==0)
		{
			int p = P-1;
			v.push_back(p);
			v.push_back(N-p+1);
		}
		else
		{
			int p = P+1;
			v.push_back(p);
			v.push_back(N-p+1);
		}
		sort(v.begin(), v.end());

		for(const auto& a : v)
		{
			cout << a << " ";
		}
		cout << "\n";
	}

}