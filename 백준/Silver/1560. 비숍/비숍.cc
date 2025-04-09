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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

	string str;
	cin >> str;


	if(str=="1") 
	{
		cout << 1;
		return 0;
	}

	int n = 0;
	int next=0;
	for(int i=str.length()-1; i>=0; i--)
	{
		n = (str[i]-'0')*2 + next;
		next=0;
		while(n>9)
		{
			n-=10;
			next+=1;
		}
		str[i] = n+'0';
		if(i==0 && next>0)
		{
			char c = next+'0';
			str = c+str;
		}
	}
	next=-2;
	for(int i=str.length()-1; i>=0; i--)
	{
		n = (str[i]-'0') + next;
		next=0;
		while(n < 0)
		{
			n+=10;
			next-=1;
		}
		str[i] = n+'0';
		while(str[i]=='0' && i==0)
		{
			str.erase(0,1);
		}
	}
	cout << str +"\n";
}