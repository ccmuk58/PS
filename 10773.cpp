#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n, sum = 0;
	stack<int> s;

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n) {
			sum += n;
			s.push(n);
		}
		else {
			sum -= s.top();
			s.pop();
		}
	}
	cout << sum;
}