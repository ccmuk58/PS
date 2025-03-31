#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 5e2 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int a[10002];
int r;
int cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;


    for(int i=0;i<N;i++) {
        cin >> a[i];
    }

    for(int i=0;i<N;i++) {
        for(int j=i;j<N;j++) {
            r += a[j];

            if(r==M) {
                cnt++;
                r==0;
                break;
            }
        }
        if(r!=0) r=0;
    }   

    cout << cnt;
}