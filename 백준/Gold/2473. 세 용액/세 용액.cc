#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
constexpr int LIMIT = 5002;

int N;
long long water[LIMIT];
int ansFront, ansMid, ansBack;

void TwoPointer()
{
	int front = 0;
	int back = N - 1;
	int mid = 1;
	long long sum = 0;
	long long ansSum = 10000000000;

	while (front < back && ansSum)
	{
		mid = front + 1;
		back = N - 1;

		while (mid < back)
		{
			sum = water[front] + water[mid] + water[back];
			if (abs(ansSum) > abs(sum))
			{
				ansSum = sum;
				ansFront = water[front];
				ansMid = water[mid];
				ansBack = water[back];
			}

			if (sum < 0)mid++;
			else		back--;
		}
		front++;
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

	cout << ansFront << " " << ansMid << " " << ansBack;
}