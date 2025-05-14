#include<bits/stdc++.h>
using namespace std;

int A,B,C,N,M,K,L;
int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	vector<int> v;

	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end());


	int l=0;
	int r=N-1;
	int t=1;
	int ans=0;
	while(M>=t && l<=r)
	{
		if(v[r]<=0)
		{
			break;
		}
		ans += v[r];
		r--;
		l++;
		t++;
	}

	cout << ans;

}