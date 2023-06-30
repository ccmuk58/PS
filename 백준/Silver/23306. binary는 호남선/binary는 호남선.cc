#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int a, b;

	cin >> N;
	cout << "? 1" << endl;
	cin >> a;
	cout << "? " << N << endl;
	cin >> b;

	if (a > b)
		cout << "! -1" << endl;
	else if (a == b)
		cout << "! 0" << endl;
	else
		cout << "! 1" << endl;
}