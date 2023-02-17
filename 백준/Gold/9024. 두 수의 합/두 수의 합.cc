#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
constexpr int LIMIT = 1000002;

int t, n;
ll k;
int S[LIMIT];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		for (int j = 0; j < n; j++)
		{
			cin >> S[j];
		}
		sort(S, S + n);

		int front = 0;
		int back = n - 1;
		ll ansSum = 2200000000;
		ll sum = 0;
		int cnt = 0;
		while (front < back)
		{
			sum = S[front] + S[back];
			if (abs(k - ansSum) > abs(k - sum))
			{
				ansSum = sum;
				cnt = 1;
			}
			else if (abs(k - ansSum) == abs(k - sum))
			{
				cnt++;
			}

			if (k < sum) back--;
			else front++;

		}
		cout << cnt << "\n";
	}

}