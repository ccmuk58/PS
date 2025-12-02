#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using plp = pair<ll, pl>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = INT64_MAX;

int a[150000];
int main()
{

	
	int idx=0;
	for(int i=0; i<150000; i++)
	{
		while(a[idx])
		{
			idx+=10007;
			idx%=150000;
		}
		a[idx] = i+1;
	}
	for(int i=0; i<150000; i++)
	{
		cout << a[i] << " ";
	}
}