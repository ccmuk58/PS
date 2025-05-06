#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int ans = 1000;
bool stu[12][12] = {};
int stcnt[12] = {};

void solve(int stuNum, bool isSolved[], int stuCnt)
{
    bool curSolved[N + 1] = {};
    
	copy(isSolved, isSolved+N+1, curSolved);

	int solveCnt = 0;
    for (int i = 1; i <= N; i++)
	{
		if(stu[stuNum][i]==true)
		{
			curSolved[i] = true;
		}
	}
    for (int i = 1; i <= N; i++)
    {
		if(curSolved[i] == true)
			solveCnt++;
    }
    if (solveCnt == N)
    {
        ans = min(ans, stuCnt);
        return;
    }
	for(int i=stuNum+1; i<=M; i++)
	{
		solve(i, curSolved, stuCnt+1);
	}
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    bool canSolve[12] = {};
    for (int i = 1; i <= M; i++)
    {
        cin >> O;
        stcnt[i] = O;
        for (int j = 1; j <= O; j++)
        {
            cin >> P;
            stu[i][P] = true;
            canSolve[P] = true;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (canSolve[i] == false)
        {
            cout << -1;
            return 0;
        }
    }

	bool solved[N+1] = {};
    for (int i = 1; i <= M; i++)
    {
		solve(i, solved, 1);
    }
    cout << ans;
}