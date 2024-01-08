#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 1;
ll n, r = 5;

int main(){
    cin >> n;
    for(ll i=1; i<=r; i++)
    {
        ans = ans * (n - r + i) / i;
    }
	cout << ans;
}