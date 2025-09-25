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
	
	cin >> N;
	

	priority_queue<int> pq;

	
	for(int i=1; i<N; i++)
	{
		pq.push(i);
	}
	int ans;
	vector<pi> v;
	while(pq.size()>1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		v.push_back({a,b});
		int c = a-b;
		pq.push(c);
	}

	int a = pq.top();
	cout << N-a << "\n";

	for(auto t : v)
	{
		cout << t.first << " " << t.second << "\n";
	}
	cout << N << " " << a << "\n";

	/*
	2
	1 2
	1
	
	1 2

	3
	1 2 3
	1 3
	2

	4
	1 2 3 4
	1 1 4
	0 4
	4

	5
	1 2 3 4 5
	1 2 1 5
	1 1 5
	0 5
	5

	6
	1 2 3 4 5 6
	1 2 3 1 6
	1 2 2 6
	1 0 6
	1 6
	6
	
	*/


}