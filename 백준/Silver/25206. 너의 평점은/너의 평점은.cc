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
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string n, len, score;

    double totalScore = 0;
	double totalTime = 0;
    for (int i = 0; i < 20; i++)
    {
        cin >> n >> len >> score;
        if (score == "P")
            continue;

        double s = 0;
        if (score == "A+")
            s = 4.5;
        else if (score == "A0")
            s = 4.0;
        else if (score == "B+")
            s = 3.5;
        else if (score == "B0")
            s = 3.0;
        else if (score == "C+")
            s = 2.5;
        else if (score == "C0")
            s = 2.0;
        else if (score == "D+")
            s = 1.5;
        else if (score == "D0")
            s = 1.0;

		totalScore+=s*stoi(len);
		totalTime += stoi(len);
    }
    double ans = totalScore/totalTime;
	cout << ans;
}