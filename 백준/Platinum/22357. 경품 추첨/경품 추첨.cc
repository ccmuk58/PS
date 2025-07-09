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

int number = 5000000;
int primeNum[5000000 + 1];
void era()
{
    for (int i = 2; i <= number; i++)
        primeNum[i] = i;

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	vector<int> pn;
    vector<int> v[31];
	era();
	
	for(int i=2000; i<=number; i++)
	{
		if(primeNum[i]>0)
		{
			pn.push_back(primeNum[i]);
		}
	}
    cin >> K >> N;
	int idx=0;
    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
			cout << 1+pn[idx]*j << " ";
        }
		cout << "\n";
		idx++;
    }

	
}