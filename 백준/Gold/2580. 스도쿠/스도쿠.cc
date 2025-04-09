#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int b[12][12];
bool fin;
vector<pi> v;
void print()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}
bool isPossible(int y, int x, int n)
{
    for (int i = 1; i <= 9; i++)
    {
        if (b[y][i] == n || b[i][x] == n)
            return false;
    }

	int ax = (x - 1) / 3;
    int ay = (y - 1) / 3;
    for (int i = ay * 3 + 1; i <= ay * 3 + 3; i++)
    {
        for (int j = ax * 3 + 1; j <= ax * 3 + 3; j++)
        {
            if (i == y && j == x)
                continue;
            if (b[i][j] == n)
                return false;
        }
    }

    return true;
}
void bt(int cnt)
{
	if(v.size() == cnt) {
		print();
		exit(0);
	}

	int y = v[cnt].first;
	int x = v[cnt].second;

	for(int i=1; i<=9; i++)
	{
		if (isPossible(y,x,i))
		{
			b[y][x] = i;
			bt(cnt+1);
			b[y][x] = 0;
		}
	}

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            char c;
            cin >> b[i][j];
			if(b[i][j]==0) v.push_back({i, j});
        }
    }

	bt(0);
}