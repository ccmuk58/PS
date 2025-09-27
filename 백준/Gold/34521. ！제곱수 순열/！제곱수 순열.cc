#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool isFail[2000002] = {};
	for(int i=1; i<=4000; i++)
	{
		if(i*i>2000000) break;
		isFail[i*i] = true;
	}
	cin.tie(0)->sync_with_stdio(0);
	int N, T;
	cin >> T;
	
	while(T--)
	{
		queue<int> q;
		deque<int> dq;
		dq.push_back(1);
		cin >> N;
		for(int i=2; i<=N; i++)
		{
			if(!q.empty())
			{
				int f = q.front();
				q.pop();
				if(isFail[dq.front()+f])
				{
					cout << -1 << "\n";
					i=N+5;
					continue;
				}
				dq.push_front(f);
			}
			if(isFail[dq.back()+i])
			{
				q.push(i);
				continue;
			}
			else
			{
				dq.push_back(i);
			}
		}
	
		if(!q.empty())
			dq.push_front(q.front());

		while(!dq.empty()){
			cout << dq.front() << " ";
			dq.pop_front();
		}
		cout << "\n";

	}
}