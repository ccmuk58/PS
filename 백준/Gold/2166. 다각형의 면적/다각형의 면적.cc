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
vector3 crossProduct(vector3 a, vector3 b) {
    vector3 v;
    v.x = a.y * b.z - a.z * b.y;
    v.y = -(a.x * b.z - a.z * b.x);
    v.z = a.x * b.y - a.y * b.x;
    return v;
}

vector3 vec[LIMIT];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    int zx, zy;
    cin >> zx >> zy;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;

        vec[i].x = x - zx;
        vec[i].y = y - zy;
        vec[i].z = 0;
    }
    double ans = 0;
	vector3 tmpV = {0,0,0};
	vector3 ansV = {0,0,0};
    for (int i = 1; i < N - 1; i++) {
        ans += crossProduct(vec[i - 1], vec[i]).z / 2;
    }
	ans = abs(ans);
    ans = round(ans*10) / 10;

	cout << fixed;
    cout << setprecision(1) << ans;
}