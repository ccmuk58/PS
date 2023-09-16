#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int LIMIT = 1e6 + 2;
const ll INF = 1e15;

int N, K, C;
ll A[12];
ll result = INF;
bool Check(ll t)
{
	ll foodSum = 0;
	for (int i = 0; i < N; i++)
		foodSum += t / A[i];

	if (foodSum >= K)
	{
		result = min(result, t);
		return true;
	}
	else
		return false;
}
void BinarySearch()
{
	ll maxT = INF;
	ll minT = 1;
	ll midT = INF / 2;
	while (minT <= maxT)
	{
		midT = (minT + maxT) / 2;
		if (Check(midT))
		{
			maxT = midT - 1;
		}
		else
		{
			minT = midT + 1;
		}
	}
}
void Solve(int sup, int idx = 0)
{
	if (sup == 0)
	{
		BinarySearch();
		return;
	}
	for (int i = idx; i < N; i++)
	{
		if (A[i] > 1)
		{
			A[i]--;
			Solve(sup - 1, i);
			BinarySearch();
			A[i]++;
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K >> C;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	Solve(C);

	cout << result;
}