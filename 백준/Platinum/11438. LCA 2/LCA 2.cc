#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = 0;

int lv[100002];
int sp[21][100002];
vector<int> v[100002];
void dfs(int n, int l, int p)
{
    sp[0][n] = p;
    lv[n] = l;

    for (int i = 0; i < v[n].size(); i++)
    {
        if (v[n][i] == p)
            continue;
        dfs(v[n][i], l + 1, n);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }

    dfs(1, 0, 0);

    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sp[i][j] = sp[i - 1][sp[i - 1][j]];
        }
    }
    cin >> M;

    while (M--)
    {
        cin >> U >> V;
        if (lv[U] > lv[V])
            swap(U, V);

        int d = lv[V] - lv[U];
        for (int i = 0; i <= 20; i++)
        {
            if (d & (1 << i))
                V = sp[i][V];
        }
		if(U==V)
		{
			cout << U << "\n";
			continue;
		}
		for (int i = 20; i >= 0; i--)
		{
			if (sp[i][U] != sp[i][V])
			{
				U = sp[i][U];
				V = sp[i][V];
			}
		}
		
        cout << sp[0][U] << '\n';
    }
}