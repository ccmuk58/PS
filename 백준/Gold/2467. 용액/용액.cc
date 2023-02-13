#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
constexpr int LIMIT = 100002;

int N;
int water[LIMIT];
int ansMin, ansMax;

void TwoPointer()
{
	int head = 0;
	int tail = N - 1;
	long long sum = 0;
	long long ansSum = 10000000000;

	while (head != tail && ansSum)
	{
		sum = water[head] + water[tail];
		if (abs(ansSum) > abs(sum))
		{
			ansSum = sum;
			ansMin = water[head];
			ansMax = water[tail];
		}

		if (sum < 0)	head++;
		else tail--;
	}
}

int main() 
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> water[i];
	}

	TwoPointer();

	cout << ansMin << " " << ansMax;
}