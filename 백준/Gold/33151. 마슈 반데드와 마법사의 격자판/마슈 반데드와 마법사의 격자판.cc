#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pll = pair<ll, pair<ll, ll>>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

vector<ll> v;
ll ans = 0;
int b[1002][1002] = {};
void print()
{
    for (int k = 0; k < N; k++)
    {
        for (int o = 0; o < N; o++)
        {
            cout << b[k][o] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    ll hf = (N * N) / 2;
    ll avg = K / (N * N);
    ll sm = avg * N * N;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        fill(b[i], b[i] + N, avg);
    }
    if (N == 1)
    {
        cout << K;
        return 0;
    }
    if (N % 2 == 0)
    {
        if (K < hf || K % 2 == 1)
        {
            cout << -1;
            return 0;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j += 2)
                {
                    if (i % 2 == 0 && j == 0)
                        j = 1;
                    b[i][j]--;
                    sm--;
                }
            }
            // 		4 78
            while (sm < K)
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j += 2)
                    {
                        if (i % 2 == abs((ll)flag - 1) && j == 0)
                            j = 1;
                        b[i][j] += 2;
                        sm += 2;
                        if (sm == K)
                        {
                            print();
                            return 0;
                        }
                    }
                }
                flag = !flag;
            }
        }
    }
    else
    {
        if (K < hf)
        {
            cout << -1;
            return 0;
        }
        else if (sm % 2 != K % 2)
        {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j += 2)
				{
					if (i % 2 == 1 && j == 0)
						j = 1;
					b[i][j]--;
					sm--;
				}
			}
            if (sm == K)
            {
                print();
                return 0;
            }
            while (sm < K)
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j += 2)
                    {
                        if (i % 2 == abs((ll)flag) && j == 0)
                            j = 1;
                        b[i][j] += 2;
                        sm += 2;
                        if (sm == K)
                        {
                            print();
                            return 0;
                        }
                    }
                }
                flag = !flag;
            }
        }
        else
        {
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j += 2)
				{
					if (i % 2 == 0 && j == 0)
						j = 1;
					b[i][j]--;
					sm--;
				}
			}

            if (sm == K)
            {
                print();
                return 0;
            }
            while (sm < K)
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j += 2)
                    {
                        if (i % 2 == abs((ll)flag - 1) && j == 0)
                            j = 1;
                        b[i][j] += 2;
                        sm += 2;
                        if (sm == K)
                        {
                            print();
                            return 0;
                        }
                    }
                }
                flag = !flag;
            }
        }
    }

    cout << -1;
}