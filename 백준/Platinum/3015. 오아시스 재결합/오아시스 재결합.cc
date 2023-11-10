#include<bits/stdc++.h>
using namespace std;
using ll = long long;

stack <pair<ll, int>> s;
ll result;
ll sumNum;
int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	ll h;
	for(int i=0; i<n; i++){
		sumNum = 0;
		cin >> h;
		while(true)
		{
			if(s.empty())
			{
				result += sumNum;
				s.push({h, 1});
				break;
			}
			else if(s.top().first > h)
			{
				result += sumNum + 1;
				s.push({h, 2});
				break;
			}
			else if(s.top().first == h)
			{
				result += sumNum + s.top().second;
				s.push({h, s.top().second + 1});
				break;
			}
			else
			{
				sumNum++;
				s.pop();
			}
		}
	}

	cout << result;
}