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
	
	
	cin >> N;
	vector<ll> g[N+2];

	int indeg[N+2] = {};
	for(int i=0; i<N-1; i++)
	{
		cin >> A >> B;

		g[A].push_back(B);
		g[B].push_back(A);
		indeg[A]++;
		indeg[B]++;
	}

	int maxindeg = 0;
	int maxidx = 0;
	for(int i=1; i<=N; i++)
	{
		if(g[i].size() > maxindeg)
		{
			maxindeg = g[i].size();
			maxidx = i;
		}
	}

	cout << 3 << '\n';
	if(maxindeg>=3)
	{
		cout << g[maxidx][0] <<" "<< g[maxidx][1] << '\n';
		cout << g[maxidx][1]<<" " << g[maxidx][2] << '\n';
		cout << g[maxidx][0]<<" " << g[maxidx][2] << '\n';
	}
	else
	{
		int newNode = 0;
		int subNode = 0;
		int otherNode = 0;
		if(g[g[maxidx][0]].size()==2)
			subNode = g[maxidx][0];
		else
			subNode = g[maxidx][1];
		
		if(g[subNode][0]!=maxidx)
			newNode = g[subNode][0];
		else
			newNode = g[subNode][1];

		if(g[maxidx][0]==subNode) otherNode = g[maxidx][1];
		else otherNode = g[maxidx][0];

		cout << otherNode<<" " << subNode << '\n';
		cout << otherNode <<" " << newNode << '\n';
		cout << newNode <<" " << maxidx << '\n';

	}


}