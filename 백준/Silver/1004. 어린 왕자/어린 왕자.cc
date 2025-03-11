#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y,
    Z;
int sx, sy, ex, ey;
int cx,cy,r;
int main() {
    cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> sx >> sy >> ex >> ey;
		cin >> N;
		while(N--){
			cin >> cx >> cy >> r;
			double sdis, edis;
			sdis = sqrt(pow(cx-sx,2) + pow(cy-sy, 2));
			edis = sqrt(pow(cx-ex,2) + pow(cy-ey, 2));
			if(sdis < r && edis < r)
				continue;
			if(sdis > r && edis > r)
				continue;
			cnt++;
		}
		cout << cnt <<"\n";
	}
}
