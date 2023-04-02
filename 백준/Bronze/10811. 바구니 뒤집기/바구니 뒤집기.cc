#include <iostream>
#include <algorithm>
using namespace std;
constexpr int LIMIT = 101;

int main() {
    int n, m, i, j;
    cin >> n >> m;
    int a[LIMIT] = {};
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    
    while (m--)
    {
        cin >> i >> j;
        for (int k = 0; k <= (j - i) / 2; k++)
        {
            swap(a[k + i], a[j - k]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}