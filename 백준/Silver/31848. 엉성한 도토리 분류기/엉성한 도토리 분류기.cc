#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int A,B,C,N,M,K,L,Q;
int main(){
	cin.tie(0)->sync_with_stdio(0);

	vector<pi> hole;
	cin >> N;
	cin >> A;
	hole.push_back({A, 1});
	for(int i=1; i<N; i++)
	{
		cin >> A;
		if(hole[hole.size()-1].first < A+i)
			hole.push_back({A+i, i+1});
	}

	vector<int> dot;
	cin >> Q;
	for(int i=0; i<Q; i++)
	{
		cin >> A;
		dot.push_back(A);
	}

	for(int i=0; i<Q; i++)
	{
		int idx = lower_bound(hole.begin(), hole.end(), make_pair(dot[i], -100))- hole.begin();
		cout << hole[idx].second << " ";
	}
}