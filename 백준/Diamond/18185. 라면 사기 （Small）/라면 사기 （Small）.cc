#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int result = 0;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while (a[i] > 0) {
            if ((i + 2 <= n) && a[i] && a[i + 1] && a[i + 2] && (a[i + 1] <= a[i + 2])) {
                int minA = min(a[i], min(a[i + 1], a[i + 2]));
                a[i] -= minA;
                a[i + 1] -= minA;
                a[i + 2] -= minA;
                result += minA * 7;
            }
            else if ((i + 1 <= n) && (a[i] && a[i + 1])) {
                a[i]--;
                a[i + 1]--;
                result += 5;
            }
            else if (a[i] > 0) {
                result += 3 * a[i];
                a[i] = 0;
            }
        }
    }
    cout << result;
}
