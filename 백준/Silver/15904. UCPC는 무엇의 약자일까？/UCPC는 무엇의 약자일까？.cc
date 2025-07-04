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
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	string str;
	vector<char> v;

	getline(cin,str);
	cin.ignore();
	
	int cnt=0;
	for(int i=0; i<str.length(); i++)
	{
		if(cnt==0 && str[i]=='U')
		{
			cnt++;
		}
		else if(cnt==1 && str[i]=='C')
		{
			cnt++;
		}
		else if(cnt==2 && str[i]=='P')
		{
			cnt++;
		}
		else if(cnt==3 && str[i]=='C')
		{
			cnt++;
			break;
		}
	}

	if(cnt==4)
	{
		cout << "I love UCPC";
	}
	else 
	{
		cout << "I hate UCPC";
	}
	
}