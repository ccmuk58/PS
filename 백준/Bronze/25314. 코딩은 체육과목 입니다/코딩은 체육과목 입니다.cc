#include<iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i+=4) 
        cout << "long ";
    cout << "int";
}