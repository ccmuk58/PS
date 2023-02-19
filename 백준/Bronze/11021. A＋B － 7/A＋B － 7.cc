#include<iostream>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int A, B, T;

	cin >> T;
	for(int i=1; i<=T; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << "\n";
	}
}