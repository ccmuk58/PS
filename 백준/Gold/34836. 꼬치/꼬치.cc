#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using plp = pair<ll, pl>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll ans = INT64_MAX;

ll a[1004][1004];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    vector<ll> v;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    /*
      2 1 3 5 4
    */
    ll a[N + 2] = {};
    ll b[N + 2] = {};
    a[0] = v[0];
    b[N - 1] = v[N - 1];
    for (ll i = 1; i < N; i++)
    {
        a[i] = max(a[i - 1], v[i]);
    }
    for (ll i = N - 2; i >= 0; i--)
    {
        b[i] = min(b[i + 1], v[i]);
    }
	bool sorted = true;
	for(int i=0; i<N; i++)
	{
		if(v[i] != i+1) sorted=false;
	}
	if(sorted) ans=0;
	
	vector<ll> l;
	vector<ll> r;

    for (int i = 0; i < N; i++)
    {
        if (a[i] == i + 1 && v[i]!= i + 1)
        {
            int j = i + 1;
            while (j < N && (v[j] == j + 1 || j+1 != b[j]))
            {
                j++;
            }
            ans = min(ans, (i + 1) * 2 + (N - j) * 2);
        }
    }

	

    for (int i = N-1; i >=0 ; i--)
    {
        if (b[i] == i + 1 && v[i]!= i + 1)
        {
            int j = i - 1;
            while (j >= 0 && (v[j] == j + 1 || j+1 != a[j]))
            {
                j--;
            }
            ans = min(ans, (j + 1) * 2 + (N - i) * 2);
        }
    }

    cout << ans;
}