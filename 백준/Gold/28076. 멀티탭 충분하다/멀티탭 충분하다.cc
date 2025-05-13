#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	
	vector<ll> v;
	for(int i=0; i<N; i++)
	{
		ll A;
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end(), greater<>());

	ll ans = 0;;
	if(N==1)
	{
		ans = v[0];
	}
	else if(N==2)
	{
		ans = v[0]+v[1]-1;
	}
	else
	{
		int d = N/3;
		int m = N%3;
		int idx = 0;
		ans += v[idx];
		idx+=d;
		if(m>=1)
		{
			idx+=1;
		}
		ans+= v[idx];
		
		idx+=d;
		if(m>=2)
		{
			idx+=1;
		}
		ans+= v[idx];

		ans-=3;
	}
	cout << ans;
}