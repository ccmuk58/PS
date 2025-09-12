#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

ll ans = 0;
vector<ll> v;
ll number = 1000002; 
ll primeNum[1000002];
void primeNumberSieve()
{
    for (ll i = 1; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (ll i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (ll j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	primeNumberSieve();
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	bool isSorted = true;
	for(int i=0; i<N-1; i++)
	{
		if(v[i]>v[i+1]) isSorted =false;
	}

	if(isSorted)
	{
		cout << "YES"; 
		return 0;
	}

	
	if(primeNum[v[0]]==0)
	{
		cout << "YES"; 
		return 0;
	}
	for(int i=0; i<N-1; i++)
	{
		if(primeNum[v[i+1]]==0)
		{
			cout << "YES"; 
			return 0;
		}

		if(v[i]!=1 && v[i+1]!=1)
		{
			cout << "YES"; 
			return 0;
		}
	}

	cout << "NO";

}