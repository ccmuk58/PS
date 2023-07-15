#include <bits/stdc++.h>
using namespace std;

long long Factorial(long long n){
    if(n < 2)
        return 1;
    return n * Factorial(n - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    cout << Factorial(N);
	return 0;
}