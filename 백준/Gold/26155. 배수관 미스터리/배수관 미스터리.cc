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
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<pip> v;
int p[300002];
int net[300002];
int per[300002] = {};
int find(int n)
{
    if (n == p[n])
        return p[n];
    return p[n] = find(p[n]);
}

void uni(int a, int b, int i)
{
    a = find(a);
    b = find(b);

	net[i] = net[i+1];
    if (a == b)
        return;
    p[b] = a;
    net[i]--;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    iota(p + 1, p + 300002, 1);
    fill(net, net + 300002, N);
    for (int i = 0; i < M; i++)
    {
		string s;
        int a, b;
        cin >> a >> b >> s;
		int d = stoi(s.substr(0, 1))*10000+stoi(s.substr(2));

		v.push_back({d, {a, b}});
        per[i] = d;

    }

    sort(v.begin(), v.end());
    sort(per, per + M);
    for (int i = M-1; i >= 0; i--)
    {
        uni(v[i].second.first, v[i].second.second, i);
    }

	// per : 4 5 7
	// net : 1 2 3 

    cin >> Q;
    while (Q--)
    {
        string s;
        cin >> s;
		int d = stoi(s.substr(0, 1))*10000+stoi(s.substr(2));
		int idx = lower_bound(per, per + M, d) - per;

		cout << net[idx] << "\n";
    }

}