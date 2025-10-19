#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

void solve()
{
	vector<ll> v;
	cin >> N;

	set<ll> s;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		s.insert(A);
	}

	cout << s.size()*2-1 << "\n";
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin>>T;
	
	while(T--)
	{
		solve();
	}
}