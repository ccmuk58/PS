#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
vector<pi> gem;
vector<int> bag;
ll gemSum;
priority_queue<int> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int N, K;

	cin >> N >> K;
	for(int i=0; i<N; i++)
	{
		int M, V;
		cin >> M >> V;
		gem.push_back({M, V});
	}
	for(int i=0; i<K; i++)
	{
		int C;
		cin >> C;
		bag.push_back(C);
	}
	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());
	
	int idx = 0;
	for(int i=0; i<K; i++)
	{
		while(idx < N && gem[idx].first <= bag[i])
		{
			pq.push(gem[idx++].second);
		}
		if(!pq.empty())
		{
			gemSum += pq.top();
			pq.pop();
		}
	}
	cout << gemSum;
}
