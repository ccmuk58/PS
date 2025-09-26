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
	
	vector<string> sv;
	char c;
	cin >> c >> N;
	string s;
	int indeg[150] = {};
	vector<int> v[150];
	for(int i=0; i<N; i++)
	{
		cin >> s;
		sv.push_back(s);
	}
	for(int i=0; i<N-1; i++)
	{
		int len=min(sv[i].length(), sv[i+1].length());
		for(int j=0; j<len; j++)
		{
			if(sv[i][j] != sv[i+1][j])
			{
				v[sv[i][j]].push_back(sv[i+1][j]);
				indeg[sv[i+1][j]]++;
				break;
			}
		}
	}
	int st=0;
	for(char i='a'; i<=c; i++)
	{
		if(st!=0 && indeg[i]==0)
		{
			cout << "AMBIGUOUS";
			return 0;
		}
		if(indeg[i]==0)
		{
			st=i;
		}
	}

	if(st==0)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	queue<char> q;
	q.push(st);
	string anss;
	while(!q.empty())
	{
		auto cur = q.front();
		q.pop();
		anss.push_back(cur);
		for(int i=0; i<v[cur].size(); i++)
		{
			if(--indeg[v[cur][i]] == 0)
			{
				q.push(v[cur][i]);
			}
		}
	}
	if(anss.length()<c-'a'+1)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	else
	{
		cout << anss;
	}
}