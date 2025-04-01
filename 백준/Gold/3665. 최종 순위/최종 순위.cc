#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e4 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

void solve()
{
	cin >> N;
    vector<int> past(LMT);
    vector<int> v[LMT] = {};
    int indegree[LMT];
	fill(indegree, indegree+N+2, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> past[i];
        for (int j = 1; j < i; j++)
        {
            v[past[j]].push_back(past[i]);
            indegree[past[i]]++;
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
		bool isChange = false;
        cin >> a >> b;
		for(int i=0; i<v[a].size(); i++)
		{
			if(v[a][i]==b)
			{
				v[a].erase(v[a].begin()+i);
				v[b].push_back(a);
				indegree[a]++;
				indegree[b]--;
				isChange=true;
				break;
			}
		}
		if(!isChange)
		{
			for(int i=0; i<v[b].size(); i++)
			{
				if(v[b][i]==a)
				{
					v[b].erase(v[b].begin()+i);
						v[a].push_back(b);
						indegree[a]--;
						indegree[b]++;
						break;
				}
			}	
		}
		
	}
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
	if (q.empty())
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
    vector<int> ans;
    while (!q.empty())
    {
        if (q.size() > 1)
        {
            cout << "?\n";
            return;
        }
        auto cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (const auto &a : v[cur])
        {
			indegree[a]--;
            if (indegree[a] == 0)
            {
                q.push(a);
            }
        }
    }
	if (ans.size()!=N)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
    for (const auto a : ans)
        cout << a << " ";
    cout << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;

    while (T--)
    {
        solve();
    }
}