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

    cin >> N;

    vector<pl> v;
    for(int i = 0; i < N; i++)
    {
        cin >> A >> B;
		// left
        v.push_back({A - B, -1});
		// right
        v.push_back({A + B, -2});
    }

    sort(v.begin(), v.end());

    stack<pl> s;
    ll ans = 1;

    for(const auto& cur : v)
    {
        if(cur.second == -1)
        {
            s.push(cur);
            continue;
        }

        ll sumW = 0;
        while(!s.empty())
        {
            auto pre = s.top();
            s.pop();

            if(pre.second == -1)
            {
                ll w = cur.first - pre.first;

                if(sumW == w)
                    ans += 2;
                else
                    ans += 1;

                s.push({w, -3});
                break;
            }
            else if(pre.second == -3)
            {
                sumW += pre.first;
            }
        }
    }

    cout << ans;
}