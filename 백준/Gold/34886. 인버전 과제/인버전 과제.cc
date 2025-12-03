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
    cin >> N >> I;

    int idx = 1;
    while (I > 0)
    {
        ll lastI = I;
		if(idx+1<=N)
        	cout << idx << " " << idx + 1 << endl;
		else
			cout << idx << " " << idx << endl;
        cin >> I;
        if (I == 0)
            break;

        if (I == lastI - 1)
        {
            cout << idx + 1 << " " << idx + 1 << endl;
            cin >> I;
        }
        else if (I == lastI + 1)
        {
            cout << idx << " " << idx << endl;
            cin >> I;
        }
        else if (I >= lastI + 1)
        {
            cout << idx << " " << idx + 1 << endl;
            cin >> I;
        }
        idx += 2;
    }
}

/*
0 1 0 1 0 : 3
0 1 0 1 0
0 1 0 1 0

0 0 -> 1 1 2이상 증가
0 1 -> 1 0 1증가
1 0 -> 0 1 1감소
1 1 -> 0 0 2이상 감소



0 1 1 0 1 : 2
0 1 1 0 1
0 0 0 0 1
0 0 1 1 1


*/