#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int b[1026][1026];
int psum[1026][1026];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A;
            b[i][j] = A;
			psum[i][j] = b[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }

	for(int i=0; i<M; i++)
	{
		cin >> A >> B >> C >> D;
		
		cout << psum[C][D] - psum[A-1][D] - psum[C][B-1] + psum[A-1][B-1] << "\n";
	}


}