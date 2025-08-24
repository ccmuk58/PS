#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, +1 +1};
constexpr int dx[] = {-1, +1, 0, 0, -1, +1, -1, +1};
constexpr int LMT = 1e5 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	

	cin >> T;
	while(T--)
	{
		cin >> N;
		int cnt=0;
		priority_queue<int> pql;
		priority_queue<int, vector<int>, greater<int>> pqg;
		
		cout << (N+1)/2 << "\n";
		for(int i=1; i<=N; i++)
		{
			cin >> A;
			if(pql.empty() || A<=pql.top())
			{
				pql.push(A);
			}
			else
			{
				pqg.push(A);
			}

			if(pql.size() - pqg.size() == 2)
			{
				auto t = pql.top();
				pql.pop();
				pqg.push(t);
			}
			else if(pqg.size() - pql.size() == 2)
			{
				auto t = pqg.top();
				pqg.pop();
				pql.push(t);
			}


			if(i%2==1)
			{
				if(cnt==10)
				{
					cout << "\n";
					cnt=0;
				}
				if(pql.size()>pqg.size())
				{
					cout << pql.top()<< " ";
				}
				else
				{
					cout << pqg.top() << " ";
				}
				cnt++;
			}
		}
		cout << "\n";
	}
}