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

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	vector<int> v;
	string dir = "NESW";
	int ans = 0;
	for(int i=0; i<10; i++)
	{
		cin >> A;
		if(A==1)
		{
			ans++;
		}
		else if(A==2)
		{
			ans+=2;
		}
		else
		{
			ans--;
		}

	}
	cout << dir[(ans+40)%4];
		
}