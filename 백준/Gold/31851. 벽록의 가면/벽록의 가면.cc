#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
ll A,B,C,N,M,K,L,R;

ll ccw(pi a, pi b, pi c)
{
	ll x1=a.first;
	ll y1=a.second;
	ll x2=b.first;
	ll y2=b.second;
	ll x3=c.first;
	ll y3=c.second;
	ll res = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
	if(res>0)
		return 1;
	else if(res<0)
	return -1;
	return 0;

}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	vector<pair<ll,ll>> p;
	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		p.push_back({A,B});
	}

	ll ans = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i==j)continue;
			for(int k=0; k<N; k++)
			{
				if(i==k || j==k)continue;
				for(int o=0; o<N; o++)
				{
					if(i==o || j==o || k==o)continue;
					ll c1 = ccw(p[i],p[j],p[k]);
					ll c2 = ccw(p[j],p[k],p[o]);
					ll c3 = ccw(p[k],p[o],p[i]);
					ll c4 = ccw(p[o],p[i],p[j]);
					if(c1 == c2 && c2 == c3 && c3 == c4)
					{
						ans++;
					}	
				}
			}
		}
	}
	ans/=8;
	cout << ans;
}