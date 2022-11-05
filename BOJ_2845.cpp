#include <iostream>
using namespace std;

int main() {
    int n, p, r;
    cin >> n >> p;
    for (int i = 0; i < 5; i++)
    {
        cin >> r;
        cout << r - n * p << " ";
    }
}