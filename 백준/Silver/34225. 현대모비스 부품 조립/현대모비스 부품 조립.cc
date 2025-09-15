#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll s = 0;
vector<pl> v;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	for(int i=0;i<N; i++)
	{
		cin >> A;
		v.push_back({A, i+1});
	}

	sort(v.begin(), v.end(), greater<>());

	ll mn=0;
	int idx=0;
	ll s = 0;
	for(int i=0;i<N; i++)
	{
		if(mn <= s+v[i].first*2)
		{
			mn=v[i].first;
			idx=i;
			s=0;
		}
		else
		{
			s+=v[i].first;
		}
	}
	cout << idx+1 << "\n";
	for(int i=0;i<idx+1; i++)
		cout << v[i].second << " ";

}