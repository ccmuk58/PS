#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	string s;

	cin >> s;

	bool isErase = false;

	for(int i=0; i<(int)(s.length())-4; i++)
	{
		if(s.substr(i, 5)=="-^-^-")
		{
			s.erase(s.begin() + i+2);
			isErase=true;
			break;
		}
	}
	if(!isErase)
	{
		for(int i=0; i<(int)(s.length())-2; i++)
		{
			if(s.substr(i, 3)=="-^-")
			{
				s.erase(s.begin()+i+1);
				isErase=true;
				break;
			}
		}
	}
	if(!isErase)
	{
		for(int i=0; i<(int)(s.length())-3; i++)
		{
			if(s.substr(i, 4)=="+-^+")
			{
				s.erase(s.begin()+i+1);
				break;
			}
			
			if(s.substr(i, 4)=="+^-+")
			{
				s.erase(s.begin()+i+2);
				break;
			}
			
			if(s.substr(i, 4)=="+^^+")
			{
				s.erase(s.begin()+i+1);
				break;
			}
		}
	}
	int ans=0;
	for(int i=0; i<(int)(s.length())-2; i++)
	{
		if(s.substr(i, 3)=="+^+")
		{
			ans++;
		}
		
		if(s.substr(i, 3)=="-^-")
		{
			ans--;
		}
	}

	cout << ans;
}