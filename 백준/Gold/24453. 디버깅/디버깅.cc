#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int ccnt[20000002];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	fill(ccnt, ccnt+20000002, 1);

	for(int i=0 ;i<M; i++)
	{
		int a;
		cin >> a;
		ccnt[a]--;
	}
	cin >> X >> Y;


	int cmax = 0;
	int csum = 0;
	for(int i=1; i<=X; i++)
	{
		csum += ccnt[i];
	}
	cmax = csum;
	
	int a=1, b=X+1;
	
	while(b<=N)
	{
		csum -= ccnt[a++];
		csum += ccnt[b++];
		cmax =  max(cmax, csum);
	}

	int human = X - cmax;
	human = max(human, Y);
	int ans = M-human;

	if(ans<0) ans = 0;
	cout << ans;

}