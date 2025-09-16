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
ll ans = INT64_MAX;
vector<ll> v;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	

	cin >> N;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> A;
			pq.push(A);
			if(pq.size()>N) pq.pop();
		}
	}
	ans = pq.top();


	cout << ans;
}