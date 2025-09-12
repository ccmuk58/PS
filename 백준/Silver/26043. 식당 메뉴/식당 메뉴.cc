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

    queue<pi> q;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if (A == 1)
        {
            cin >> B >> C;
            q.push({B, C});
        }
        else
        {
            cin >> B;
            auto cur = q.front();
            q.pop();
            if (cur.second == B)
            {
                a.push_back(cur.first);
            }
            else
            {
                b.push_back(cur.first);
            }
        }
    }
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		c.push_back(cur.first);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
    if (a.size() == 0)
        cout << "None";
    else
    {
        for (auto i : a)
        {
            cout << i << " ";
        }
    }
	cout << "\n";

    if (b.size() == 0)
        cout << "None";
    else
    {
        for (auto i : b)
        {
            cout << i << " ";
        }
    }
	cout << "\n";

    if (c.size() == 0)
        cout << "None";
    else
    {
		for (auto i : c)
        {
            cout << i << " ";
        }
    }
}