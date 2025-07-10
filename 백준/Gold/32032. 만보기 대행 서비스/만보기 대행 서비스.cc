#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> D;

    vector<ll> v;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    v.push_back(0);
    sort(v.begin(), v.end());

    ll ans = 10000000000000;
	
	v[0] = abs(v[0]);
    v[N] = abs(v[N]);
	// v[N]이 더 크게
    if (v[0] > v[N])
    {
        swap(v[0], v[N]);
    }
	if(v[0] == 0 || v[N]==0)
	{
		ans = max(v[0], v[N])*2 +  D;
		cout << ans;
		return 0;
	}

	ans = min(ans, v[0]*2  + v[N]*2 + D*2);
	ans = min(ans, v[0]*4 + v[N]*2 + D);
	if((v[N]+v[0])*2>=D)
	{
		ans  = min(ans, v[0]*4 + v[N]*4);
	}
	else
	{
		ans  = min(ans, v[0]*2 + v[N]*2 + D);
	}
    cout << ans;
}