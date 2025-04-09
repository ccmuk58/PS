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
map<char, int> ma;
map<char, int> mb;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string a;
    string b;

    cin >> a;
    cin >> b;

	for(int i=0; i<a.length(); i++)
	{
		ma[a[i]]++;
		mb[b[i]]++;
	}

	for(char i = 'A'; i<='Z'; i++)
	{
		if(ma[i] != mb[i])
		{
			cout << -1;
			return 0;
		}
	}

    int ans = 0;
	int i=a.length()-1;
	int j=b.length()-1;
    while (i>=0)
    {
		if(a[i] == b[j])
		{
			i--;
			j--;
		}
		else 
		{
			i--;
		}
    }
	cout << j+1;
}