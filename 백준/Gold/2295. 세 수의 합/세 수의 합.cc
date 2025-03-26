#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 15e2 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


int ans;
vector<int> v;
vector<int> s;

void solve()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int ts = v[i]-v[j];

			bool isFind = binary_search(s.begin(), s.end(), ts);
			
			if(isFind)
			{
				ans = max(ans, v[i]);
			}
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cin >> V;
		v.push_back(V);

	}
		
	sort(v.begin(), v.end());
	
	for(int i=0; i<N; i++)
		for(int j=i; j<N; j++)
			s.push_back(v[i]+v[j]);

	sort(s.begin(), s.end());

	solve();

	cout << ans;
}