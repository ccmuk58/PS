#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	int indeg[N+2]={};
	int v[N+2] ={};
	for(int i=1; i<=N; i++)
	{
		int A;
		cin >> A;

		v[i] = A;
		indeg[A]++;
	}
	vector<int> ansv;
	deque<int> dq;
	dq.push_front(1);
	while(!dq.empty())
	{
		auto cur = dq.front();
		dq.pop_front();
		ansv.push_back(cur);
		if(v[cur]==0) continue;

		dq.push_front(v[cur]);
		indeg[v[cur]]--;
		v[cur]=0;
	}

	for(int i=2; i<=N; i++)
	{
		if(v[i]!=0 && indeg[i]==0)
		{
			dq.push_front(i);
		}
		
		while(!dq.empty())
		{
			auto cur = dq.front();
			dq.pop_front();
			ansv.push_back(cur);
			if(v[cur]==0) continue;
			
			dq.push_front(v[cur]);
			indeg[v[cur]]--;
			v[cur]=0;
		}
	}


	for(int i=1; i<=N; i++)
	{
		if(indeg[i]>0)
		{
			dq.push_back(i);
		}
		while(!dq.empty())
		{
			auto cur = dq.front();
			dq.pop_front();
			ansv.push_back(cur);
			if(v[cur]!=0)
			{
				dq.push_front(v[cur]);
				indeg[v[cur]]--;
				v[cur]=0;
			}
		}	
	}

	cout << ansv.size()-1 << "\n";
	for(int i=1;i<ansv.size(); i++)
	{
		cout << ansv[i] << " ";
	}


}