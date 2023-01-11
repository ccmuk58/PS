#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#define PAIR pair<int,int>
using namespace std;



PAIR StackPop(stack<PAIR>& s) {
	PAIR p;
	p = s.top();
	s.pop();
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, h;
	stack<PAIR> s, temp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		while (true) {
			if (s.size() == 0) {
				s.push({ l,h });
				while (temp.size() > 0)	s.push(StackPop(temp));
				break;
			}
			else if (s.top().first > l) {
				s.push({ l,h });
				while (temp.size() > 0)	s.push(StackPop(temp));
				break;
			}
			else temp.push(StackPop(s));
		}
	}
	int sum = 0, max = 0;
	PAIR col = StackPop(s);
	for (int i = 0; i < n - 1; i++) {
		if (col.second < s.top().second) {
			cout << col.second << ", " << s.top().first << ", " << col.first << ", " << col.second * (s.top().first - col.first) << "\n";
			sum += col.second * (s.top().first - col.first);
			col = StackPop(s);
		}
		else if (i == n - 2) {
			cout << s.top().second * (s.top().first - col.first) << "!!\n";
			sum += s.top().second * (s.top().first - col.first);
		}
		else StackPop(s);
		if (max < col.second) max = col.second;
	}
	sum += max;
	cout << sum;
}