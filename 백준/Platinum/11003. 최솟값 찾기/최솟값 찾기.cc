#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 5000001;
using pi = pair<int, int>;

vector<pi> A(LIMIT);
// value , index
priority_queue<pi, vector<pi>, greater<pi>> pq;
int left, right;
int N, L;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> L;
	for(int i=1; i<=N; i++)
	{
		int num;
		cin >> num;
		pq.push({num, i});
		while(!pq.empty() && pq.top().second < i-L+1)
		{
			pq.pop();
		}
		cout << pq.top().first << " ";
	}
}