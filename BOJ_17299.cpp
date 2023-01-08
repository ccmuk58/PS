#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#define RANGE 1000002
using namespace std;

int n, a[RANGE] = { 0 }, f[RANGE] = { 0 };

int getNGF(stack<int> s, int index) {
	int ngf = -1;

	if (f[a[index]] < f[a[index+1]]) {
		ngf = a[index + 1];
	}
	else {
		while (!s.empty()) {
			if (s.top() != -1)
			{
				if (f[a[index]] < f[s.top()]) {
					ngf = s.top();
					break;
				}
			}
			s.pop();
		}
	}
	return ngf;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	stack<int> ngf;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

	for (int i = n; i > 0; i--) {
		ngf.push(getNGF(ngf, i));
	}

	while (!ngf.empty()) {
		cout << ngf.top() << " ";
		ngf.pop();
	}
}