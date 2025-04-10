#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int m;
int midx;
int s;
vector<int> v;
priority_queue<pi> pq;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> K >> N;

	for(int i=1; i<=N; i++)
	{
		int c;
		cin >> c;
		pq.push({c, i});
	}
 
	pi pre;
	pi cur;
	while(!pq.empty())
	{
		pi cur = pq.top();
		pq.pop();
		v.push_back(cur.second);
		cur.first--;

		if(pre.first > 0)
			pq.push(pre);
		
		pre = cur;
	}

	for(int i=0; i<pre.first; i++)
	{
		v.push_back(pre.second);
	}

	for(int i=1; i<K; i++)
	{
		if(v[i-1] == v[i])
		{
			cout << -1;
			return 0;
		}
	}
	for(int i=0; i<K; i++)
	{
		cout << v[i] << " ";
	}

}