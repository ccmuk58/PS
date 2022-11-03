#include <iostream>
using namespace std;

int main()
{
	int p, n, a, b, sum = 0;
	cin >> p;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}
	
	if (sum == p)
		cout << "Yes";
	else
		cout << "No";
}