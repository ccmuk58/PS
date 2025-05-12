#include<bits/stdc++.h>
using namespace std;

// 0: 왼뒤 1: 위뒤 2: 오뒤 3:아래뒤
int qs=0;
int b=0;
int w=0;
deque<char> dq;

void gravity()
{
	if(!dq.empty())
	{
		if(qs==1)
		{
			while(!dq.empty() && dq.front()!='w')
			{
				dq.pop_front();
				b--;
			}
		}
		else if(qs==3)
		{
			while(!dq.empty() && dq.back()!='w')
			{
				dq.pop_back();
				b--;
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int Q;
	cin >> Q;
	

	while(Q--)
	{
		string cmd;
		cin >> cmd;
		if(cmd=="pop")
		{
			if(!dq.empty())
			{
				if(dq.front()=='b')
					b--;
				else if(dq.front()=='w')
					w--;
				dq.pop_front();
				gravity();
			}
		}
		else
		{
			char c;
			cin >> c;

			if(cmd=="push")
			{
				dq.push_back(c);
				if(c=='w') w++;
				else b++;
				gravity();
			}
			else if(cmd=="rotate")
			{
				if(c=='r')
				{
					qs++;
					if(qs>3) qs=0;
					gravity();
				}
				else if(c=='l')
				{
					qs--;
					if(qs<0) qs=3;
					gravity();
				}
			}
			else if(cmd=="count")
			{
				if(c=='b')
					cout << b << "\n";
				else if(c=='w')
					cout << w << "\n";
			}
		}
	}
}