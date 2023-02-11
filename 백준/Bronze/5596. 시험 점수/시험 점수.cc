#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a = 0;
    int b = 0;
    int input;
    for (int i = 0; i < 4; i++) {
        cin >> input;
        a += input;
    }
    for (int i = 0; i < 4; i++) {
        cin >> input;
        b += input;
    }
    cout << max(a, b);
}