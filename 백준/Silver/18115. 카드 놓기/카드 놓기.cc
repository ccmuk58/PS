#include <bits/stdc++.h>
using namespace std;

int n; 
deque<int>dq;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	vector<int>v(n);

	for (int i = 0; i < n; i++) 
		cin >> v[i];

	int card = 1;
	for (int i = n - 1; i >= 0; i--) {

		if (v[i] == 1) {
			dq.push_back(card);
		}else if (v[i] == 2) {
			int b = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(b);
		}else if (v[i] == 3) {
			dq.push_front(card);
		}
		card++;
	}

	for (int i = n-1; i >=0; i--) 
		cout << dq[i] << " ";
}