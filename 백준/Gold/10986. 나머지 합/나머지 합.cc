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
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll cnt[1002];
vector<ll> s(1000002);
ll ans;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;

	for(int i=0; i<N; i++)
	{
		ll q;
		cin >> q;
		if(i!=0) s[i] = s[i-1];
		s[i] = (s[i]+q)%M;
		if(s[i]==0) ans++;
		cnt[s[i]]++;
	}

	for(int i=0; i<M; i++)
	{
		if(cnt[i]==0) continue;
		ans += cnt[i] * (cnt[i]-1) / 2;
	}
	cout << ans;
}