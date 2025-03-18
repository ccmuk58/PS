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

struct vector3 {
    double x, y, z;
};
double cross(vector3 a, vector3 b)
{
	return a.x*b.y-a.y*b.x;
}

vector3 p[LIMIT];
vector3 v[LIMIT];
int main() {
    cin.tie(0)->sync_with_stdio(0);

	for(int i=0; i<3; i++)
    	cin >> p[i].x >> p[i].y;

		for(int i=1; i<3; i++)
		{
			v[i-1].x = p[i].x - p[0].x;
			v[i-1].y = p[i].y - p[0].y;
		}
		double n = cross(v[0], v[1]);

		if(n==0) cout << 0;
		else if(n>0) cout << 1;
		else cout << -1;
}