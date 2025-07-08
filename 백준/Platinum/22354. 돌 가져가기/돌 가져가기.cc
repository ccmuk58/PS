#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string str;
    vector<pair<ll, char>> v;
    cin >> N;

    ll ans = 0;
    cin >> str;
    cin >> A;
    v.push_back({A, str[0]});
    int idx = 0;
    for (int i = 1; i < N; i++)
    {
        cin >> A;
        if (str[i] == v[idx].second)
        {
            v[idx].first = max(A, v[idx].first);
        }
        else
        {
            v.push_back({A, str[i]});
            idx++;
        }
    }


	if(idx<2)
	{
		cout << 0;
		return 0;
	}
	sort(v.begin()+1, v.end()-1, greater<>());

	for(int i=1; i<(idx)/2+1; i++)
	{
		ans += v[i].first;
	}
    cout << ans;
}