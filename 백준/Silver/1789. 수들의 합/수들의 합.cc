#include<iostream>
using namespace std;

long long S, N;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> S;

	while (S >= ++N)
	{
		S -= N;
	}

	cout << N - 1;
}