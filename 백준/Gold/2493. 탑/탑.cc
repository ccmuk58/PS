#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int N;
stack<pi> towers;
queue<int> result;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	int t;
	for(int i=1; i<=N; i++)
	{
		cin >> t;
		while(!towers.empty())
		{
			if(towers.top().first<t)
			{
				towers.pop();
			}
			else
			{
				result.push(towers.top().second);
				towers.push({t, i});
				break;
			}
		}
		if(towers.empty())
		{
			result.push(0);
			towers.push({t, i});
		}
	}
	while(!result.empty())
	{
		cout << result.front() << " ";
		result.pop();
	}
}
