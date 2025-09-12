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

ll ans = 0;
vector<ll> v;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> N >> S >> E;
	S-=1;
	E-=1;
	if(S>E) swap(S,E);

	for(int i=0; i<N; ++i)
	{
		cin >> A;
		v.push_back(A);
	}
	cin >> K;

	ll indis = E-S+1;

	if(indis > K)
	{
		cout << 0;
		return 0;
	}
	ll mxK=0;

	ll rock=0;
	for(int i=S; i>=0; --i)
	{
		rock+=v[i];
		if(v[i]==1) break;
	}
	for(int i=S+1; i<=E; i++)
	{
		rock+=v[i];
	}
	if(v[E]>1)
	{
		for(int i=E+1; i<N; ++i)
		{
			rock+=v[i];
			if(v[i]==1) break;
		}
	}

	cout << (rock>=K? 1 : 0);
	

}