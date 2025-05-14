#include <bits/stdc++.h>
using namespace std;

int A, B, C, N, M, K, L, Q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;

    cin >> N;
    cin >> s;
    cin >> Q;

   
    while (Q--)
    {
        int l, r;
        cin >> l >> r;

		int ans=0;
		
		string str;
		for(int i=l-1; i<r; i++)
		{
			str.push_back(s[i]);
		}
		for(int d=1; d<str.length(); d++)
		{
			
			string s1;
			string s2;
			int cnt=0;
			for(int i=0; i<d; i++)
			{
				s1.push_back(str[i]);
			}
			for(int i=str.length()-1; i>=d; i--)
			{
				s2.push_back(str[i]);
			}
			if(s1.size()<s2.size())
			{
				swap(s1,s2);
			}
			for(int i=s1.length()-s2.length(); i<s1.length(); i++)
			{
				if(s1[i]==s2[i-s1.length()+s2.length()])
				{
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}


		cout << ans << "\n";
    }
}