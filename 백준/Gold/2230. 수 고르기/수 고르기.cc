#include <bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 1e5 + 2;
const int INF = 1e8 * 21;

int a[LIMIT];
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, less<int>());

	int front = 0;
	int back = 0;
	int result = INF;
	while (front < n)
	{
		int diff = a[back] - a[front];
		
		if(diff >= m)
			result = min(result, diff);

		if (diff > m || back >= n-1) front++;
		else back++;
	}
	cout << result;
}