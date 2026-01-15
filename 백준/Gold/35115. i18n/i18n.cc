#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A, M , K, B;
string s1, s2;
vector<char> v[256];
bool vstd[3002][3002] = {};
void go(int st, int s2idx)
{
	vstd[st][s2idx] = true;
	if(s2idx == s2.length() && st==s1.length())
	{
		cout << "Yes";
		exit(0);
	}
	if(s2idx>=s2.length() || st>=s1.length())
	{
		return;
	}

	if(s2[s2idx]<='0'||s2[s2idx]>'9')
	{
		if(s1[st]==s2[s2idx] && !vstd[st+1][s2idx+1])
		{
			go(st+1, s2idx+1);
		}
		else
		{
			return;
		}
	}
	else	// 1~9 숫자
	{
		if(s1[st]==s2[s2idx] && !vstd[st+1][s2idx+1])
		{
			go(st+1, s2idx+1);
		}

		int ni[4] = {};
		for(int i=0; i<4; i++)
		{
			if(s2[s2idx+i] <'0'|| s2[s2idx+i]>'9') break;
			int n = 0;
			int m = 1;

			ni[i] = s2[s2idx+i]-'0';
			for(int k=i; k>=0; k--)
			{
				n += ni[k]*m;
				m*=10;
			}
			if(st+n<=s1.length() && !vstd[st+n][s2idx+i+1])
				go(st+n, s2idx+i+1);
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> s1;
	cin >> s2;
	ll len = s1.length();
	for(int i=0; i<len; i++)
	{
		v[s1[i]].push_back(i);
	}

	go(0, 0);

	cout << "No";
}