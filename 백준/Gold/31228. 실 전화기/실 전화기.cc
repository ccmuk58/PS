#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

	ll n, k;
	cin >> n >> k;
	if(k > n/2)
		k = n-k;
	if(n%k == 0 || n <= 4 || n == 6){
		cout << 0;
		return 0;
	}

	ll a=n;
	ll b=k;
	ll r;
	while(b != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	n/=a;
	k/=a;
	cout << n*(k-1);
}