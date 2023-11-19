#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, less<int>> less_pq;
priority_queue<int, vector<int>, greater<int>> greater_pq;
int n;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (greater_pq.size() == less_pq.size())
            less_pq.push(num);
        else
            greater_pq.push(num);

        if (!greater_pq.empty() && !less_pq.empty()) {
            if (less_pq.top() > greater_pq.top()) {
                int a = less_pq.top();
                int b = greater_pq.top();
                less_pq.pop();
                greater_pq.pop();
                less_pq.push(b);
                greater_pq.push(a);
            }
        }
		cout << less_pq.top() << "\n";
    }
}
