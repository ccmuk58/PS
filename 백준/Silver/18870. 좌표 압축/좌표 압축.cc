#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

bool compare(pi a, pi b)
{
	return a.second < b.second;
}
int ans;
vector<pi> v;
int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for(int i=0; i<N; i++)
	{
		int n;
		cin >> n;
		v.push_back({i, n});
	}
	sort(v.begin(), v.end(), compare);
	int last=200000000;
	int seq=0;
	for(int i=0; i<N; i++)
	{
		int cur = v[i].second;
		if(last==cur) seq+=1;
		else last = cur;
		v[i].second = i-seq;
	}
	sort(v.begin(), v.end());

	for(auto a : v)
	{
		cout << a.second << " ";
	}
}
