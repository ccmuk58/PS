#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {-1, -1, 0, 0, 0, +1, +1};
constexpr int dx[] = {-1, 0, -1, 0, +1, 0, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int a[1002][1002] = {};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll ans = 0;

    cin >> N;

    int n = N;

	if(N==2 || N==3)
	{
		cout << -1;
		return 0;
	}
	if(N==1)
	{
		cout << 1;
		return 0;
	}

	a[1][1] = 4;
	a[2][1] = 2;
	a[2][2] = 3;
	a[3][1] = 3;
	a[3][2] = 4;
	a[3][3] = 2;
	a[4][1] = 4;
	a[4][2] = 1;
	a[4][3] = 3;
	a[4][4] = 4;

    for (int i = 5; i <= N; i++)
    {
    	for (int j = 1; j <= i; j++)
		{
			a[i][j] = i;
		}
		
		int cnt=1;
		for (int k = 1; k <= N; k++)
		{
			for (int j = 1; j <= k; j++)
			{
				if(a[k][j] == i-3)
				{
					swap(a[k][j], a[i][2*cnt]);
					cnt++;
				}
				if(cnt>i/2)
				{
					k=10000;
					break;
				}
			}
		}

    }
	

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}