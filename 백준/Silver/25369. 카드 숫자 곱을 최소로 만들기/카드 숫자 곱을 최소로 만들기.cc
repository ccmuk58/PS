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

ll mul = 1;
ll ans = 1;
vector<ll> v;
vector<ll> deck;
bool isClear;
void go(int cnt)
{
	if(cnt==N) return;
	for(int i=1; i<=9; ++i)
	{
		ans*=i;
		go(cnt+1);
		if(cnt==N-1 && ans>mul)
		{
			isClear = true;
		}
		if(isClear){ 
			deck.push_back(i);
			return;
		}
		ans/=i;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	
	cin >> N;
	for(int i=0; i<N; ++i)
	{
		cin >> A;
		mul*=A;
	}

	go(0);

	if(deck.size()==0) cout << -1;
	else
	{
		sort(deck.begin(), deck.end());
		for(int i=0; i<N; ++i)
		{
			cout << deck[i] << " ";
		}
	}

	


}