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
	ll v[N+2];
	
	queue<pl> q;

	vector<ll> ans;
	q.push({1, N});

	while(!q.empty())
	{
		auto [n, cnt] = q.front();
		q.pop();
		if(cnt==1)
		{
			ans.push_back(n);
			continue;
		}

		q.push({n*2, cnt-1});
		if(n-1>3 && (n-1)%3==0 && ((n-1)/3)%2==1)
			q.push({(n-1)/3, cnt-1});
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for(int i=0; i<ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	

}