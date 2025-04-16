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

vector<int> v[100002];
int indegree[100002];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
        indegree[A]++;
        indegree[B]++;
    }

    queue<int> q;
    queue<int> nq;
    vector<int> ans;

    for (int i = 0; i < N; i++)
        if (indegree[i] == 1)
            q.push(i);

    while (q.size() > 2)
    {
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            indegree[a] = 0;
            for (int i = 0; i < v[a].size(); i++)
            {
				int adj = v[a][i];
                indegree[adj]--;
                if (indegree[adj] == 1)
                    nq.push(adj);
                else if (indegree[adj] == 0)
                    ans.push_back(adj);
            }
        }

        while (!nq.empty())
        {
            q.push(nq.front());
            nq.pop();
        }
    }

    for (int i = 0; i < N; i++)
        if (indegree[i] > 0)
            ans.push_back(i);

    sort(ans.begin(), ans.end());

    for (auto a : ans)
    {
        cout << a << " ";
    }
}