#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
list<ll> l;
unordered_map<ll, list<ll>::iterator> um;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	ll ans =0;
	vector<ll> v;
	ll arr[N+2]={};

	for(int i=0; i<N; i++)
	{
		cin >> A;
		l.push_back(A);
		um[A] = prev(l.end());
	}

	while(M--)
	{
		string str;
		cin >> str;
		list<ll>::iterator it;
		if(str=="BN")
		{
			cin >> A >> B;
			it = um[A];
			if(next(it)==l.end())
			{
				it = l.begin();
			}
			else
			{
				it = next(it);
			}
			cout << *it << "\n";
			l.insert(it, B);
			um[B] = prev(it);
		}
		else if(str=="BP")
		{
			cin >> A >> B;
			it = um[A];
			if(it==l.begin())
			{
				it = l.end();
			}
			cout << *prev(it) << "\n";
			l.insert(it, B);
			um[B] = prev(it);
		}
		else if(str=="CN")
		{
			cin >> A;
			it = um[A];
			if(next(it)==l.end())
			{
				cout << l.front() << "\n";
				l.pop_front();
			}
			else
			{
				cout << *next(it) << "\n";
				l.erase(next(it));
			}
		}
		else if(str=="CP")
		{

			cin >> A;
			it = um[A];
			if(it==l.begin())
			{
				cout << l.back() << '\n';
				l.pop_back();
			}
			else
			{
				cout << *prev(it) << "\n";
				l.erase(prev(it));
			}
		}
	}


}