#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
constexpr int LIMIT = 100002;

int N;
int water[LIMIT];
int ansFront, ansBack;

void TwoPointer()
{
	int front = 0;
	int back = N - 1;
	long long sum = 0;
	long long ansSum = 10000000000;

	while (front != back && ansSum)
	{
		sum = water[front] + water[back];
		if (abs(ansSum) > abs(sum))
		{
			ansSum = sum;
			ansFront = water[front];
			ansBack = water[back];
		}

		if (sum < 0) front++;
		else back--;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> water[i];
	}

	sort(water, water + N);

	TwoPointer();

	cout << ansFront << " " << ansBack;
}