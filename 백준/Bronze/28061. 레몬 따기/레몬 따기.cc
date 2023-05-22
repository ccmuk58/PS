#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		int lemon;
		cin >> lemon;
		lemon -= (N - i);
		result = max(result, lemon);
	}
	cout << result;
}