#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pdp = pair<double, pi>;
constexpr int LIMIT = 1e3 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


pi pos[LIMIT];
int parent[LIMIT];
int s;
double ans;
double getDistance(pi a, pi b)
{
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}
int find(int n)
{
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}
bool uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a==b) return false;
	parent[a] = b;
	return true;
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	iota(parent+1, parent+LIMIT, 1);

	cin>>N>>M;
	priority_queue<pdp, vector<pdp>, greater<pdp>> pq;

	for(int i=1; i<=N; i++)
	{
		cin >> X >> Y;
		pos[i] = {X, Y};
		for(int j=i-1; j>0; j--)
		{
			double d = getDistance(pos[i], pos[j]);
			pq.push({d, {i,j}});
		}
	}
	for(int i=0; i<M; i++)
	{
		cin >> X >> Y;
		pq.push({0,{X, Y}});
	}
	while(s<N-1)
	{
		auto cur = pq.top();
		pq.pop();

		if(uni(cur.second.first, cur.second.second))
		{
			s++;
			ans+=cur.first;
		}
	}
	ans = round(ans*100);
	ans /= 100;
	cout << fixed;
	cout.precision(2);
	cout << ans;

}