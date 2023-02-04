#include<iostream>
using namespace std;
constexpr int LIMIT = 120;

int N;
int a[LIMIT];
int prime[LIMIT];
string ans[LIMIT];

void solve(int i)
{
	for (int j = 2; j < LIMIT; j++)
	{
		for (int k = 2; k < LIMIT; k++)
		{
			if (j + k != a[i]) continue;
			if (!prime[j] && !prime[k])
			{
				ans[i] = "Yes";
				return;
			}
		}
	}
	ans[i] = "No";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];

	for (int i = 2; i < LIMIT; i++)
	{
		int j = i;
		while (i*j<LIMIT)
		{
			prime[i * j] = 1;
			j++;
		}
	}

	for (int i = 0; i < N; i++)
		solve(i);

	for (int i = 0; i < N; i++)
		cout << ans[i] << "\n";
}
