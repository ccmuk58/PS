#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 5e5;
constexpr ll MOD = 1'000'000'007;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while(T--)
	{
		string cmd;
		cin >> cmd;
		cin >> N;
		string nstr;
		cin >> nstr;
		nstr = nstr.substr(1, nstr.length()-1);
		vector<int> v;
		if(N!=0)
		{
			for(int i=0; i<nstr.length();)
			{
				for(int j=i;;j++)
				{
					if(nstr[j]==',' || nstr[j]==']')
					{
						v.push_back(stoi(nstr.substr(i, j-i)));
						i=j+1;
						break;
					}
				}
			}
		}
		int l=0;
		int r=N-1;
		bool inv=false;

		for(int i=0; i<cmd.length(); i++)
		{
			if(cmd[i]=='R')
			{
				inv = !inv;
			}
			else
			{
				if(!inv)
				{
					l++;
				}
				else
				{
					r--;
				}
			}
		}
		if(l-1>r)
		{
			cout << "error\n";
			continue;
		}
		cout << "[";
		if(!inv)
		{
			for(int i=l; i<r; i++)
				cout << v[i] <<",";

			if(l <= r)
			cout << v[r];
		}
		else
		{
			for(int i=r; i>l; i--)
				cout << v[i] <<",";
			
			if(l <= r)
			cout << v[l];
		}
		cout << "]\n";

	}
	
}
