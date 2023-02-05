#include<iostream>
#include<algorithm>
using namespace std;

int n[3];
int main()
{
    for (int i = 0; i < 3; i++)
        cin >> n[i];
    sort(n, n + 3);
    for (int i = 0; i < 3; i++)
        cout << n[i] << " ";
}