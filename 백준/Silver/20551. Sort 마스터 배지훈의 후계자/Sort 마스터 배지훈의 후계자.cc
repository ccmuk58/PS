#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	vector<int> v;

	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<M; i++)
	{
		cin >> A;
		int idx = lower_bound(v.begin(), v.end(), A) - v.begin();
		if(idx>=N || v[idx]!=A)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << idx << "\n";
		}

	}
}