#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LIMIT = 1e5 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    vector<int> v;
	queue<int> q;
    cin >> N >> K;

	for(int i=0; i<N; i++)
	{
		cin >> A;
		v.push_back(A);
	}

	int cnt=0;
	
	for(int i=0; i<N; i++)
	{
		if(!q.empty() && q.front()==i)q.pop();
		if(!q.empty() && q.size()%2==1)
			v[i]=abs(v[i]-1);
		if(i > N-K)
		{
			if(v[i]==1)
			{
				cout << "Insomnia";
				return 0;
			}
		}
		else if(v[i]==1)
		{
			q.push(i+K);
			v[i]=0;
			cnt++;
		}
	}
	cout << cnt;
}