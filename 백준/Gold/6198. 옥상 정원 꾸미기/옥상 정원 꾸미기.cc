#include <bits/stdc++.h>
using namespace std;
stack<long long> s;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    long long result = 0;
    long long cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        while (true) {
			if(s.empty()) {
                s.push(cur);
				break;
			}
            else if (s.top() > cur) {
                result += s.size();
                s.push(cur);
                break;
            } else {
                s.pop();
            }
        }
    }
	cout << result;
}