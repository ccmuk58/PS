#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int blue;
int white;
int b[130][130];
void cut(pi s, int sz)
{
	if(sz==1) {
		if(b[s.first][s.second]==1)
			blue++;
		else
			white++;
		return;
	}

	int f = b[s.first][s.second];
	for(int i=s.first; i<s.first+sz; i++)
	{
		for(int j=s.second; j<s.second+sz; j++)
		{
			if(f!=b[i][j])
			{
				cut(s, sz/2);
				cut({s.first+sz/2, s.second}, sz/2);
				cut({s.first+sz/2, s.second+sz/2}, sz/2);
				cut({s.first, s.second+sz/2}, sz/2);
				return;
			}
		}
	}
	if(f==1)
		blue+=1;
	else
		white+=1;
	return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> b[i][j];
		}
	}
	cut({0,0},N);
	cout << white << "\n";
	cout << blue;
}