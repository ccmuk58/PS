#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll fibonacci[92] = {0, 1};
	int n;

	cin >> n;

	for (int i = 2; i <= n; i++)  
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

	cout << fibonacci[n];
}