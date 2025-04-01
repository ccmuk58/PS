#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int sorted[LMT];
ll ans;
void merge(vector<int> &v, int start, int mid, int end)
{
    int a = start;
    int b = mid + 1;
    int c = start;

    while (a <= mid && b <= end)
    {
        if (v[a] > v[b])
        {
            sorted[c++] = v[b++];
            ans += mid - a + 1;
        }
        else
            sorted[c++] = v[a++];
    }
    if (a > mid)
    {
        while (b <= end)
            sorted[c++] = v[b++];
    }
    else
    {
        while (a <= mid)
            sorted[c++] = v[a++];
    }
    for (int i = start; i <= end; i++)
        v[i] = sorted[i];
}
void merge_sort(vector<int> &v, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    merge_sort(v, start, mid);
    merge_sort(v, mid + 1, end);

    merge(v, start, mid, end);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> v(N + 2);
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    merge_sort(v, 1, N);
    cout << ans;
}