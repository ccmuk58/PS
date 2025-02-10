#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;


int N, K;
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;

	int ans=1;
	for(int i=0; i<K; i++)
	{
		ans *= N-i;
		ans /= i+1;
	}
	cout << ans;

}