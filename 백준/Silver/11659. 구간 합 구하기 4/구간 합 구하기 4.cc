#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e4 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<ll> v(100002);
vector<ll> ps(100002);
int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	for(int i=1; i<=N; i++)
		cin >> v[i];

	ps[1] = v[1];

	for(int i=2; i<=N; i++)
		ps[i] = v[i] + ps[i-1];

	for(int i=0; i<M; i++)
	{
		ll a, b;
		ll ans = 0;
		cin >> a >> b;
		ans  = ps[b];
		if(a>1) ans -= ps[a-1];
		cout << ans << "\n";
	}	

	
}