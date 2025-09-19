#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1, +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr ll MOD = 1e9 + 7;
constexpr ll LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	priority_queue<int> spacepq;
	priority_queue<pi> taskpq;
	vector<pi> v;
	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		v.push_back({A, B});
		spacepq.push(-(i+1));
	}
	sort(v.begin(), v.end());

	int idx= 0;
	int t = 0;
	int mx = 0;
	int cnt[N+2] = {};
	while(idx<v.size() || !taskpq.empty())
	{
		if(v[idx].first == t)
		{

			auto cur = -spacepq.top();
			spacepq.pop();
			taskpq.push({-v[idx].second,cur});
			mx = max(mx, cur);
			cnt[cur]++;
			idx++;
		}

		if(!taskpq.empty() && -taskpq.top().first==t)
		{
			auto space = taskpq.top().second;
			taskpq.pop();
			spacepq.push(-space);
		}
		t++;
	}

	cout << mx << "\n";
	for(int i=1; i<=mx; i++)
	{
		cout << cnt[i] << " ";
	}

}