#include<iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 2002;

int N;
int A[LIMIT];
int ans;

void TwoPointers()
{
	int front;
	int back;
	int sum;
	for (int i = 0; i < N; i++)
	{
		front = 0;
		back = N - 1;
		while (front < back)
		{
			if (front == i)
			{
				front++;
				continue;
			}
			else if (back == i)
			{
				back--;
				continue;
			}

			sum = A[front] + A[back];
			
			if (A[i] == sum)
			{
				ans++;
				break;
			}
			else if (A[i] > sum) front++;
			else if (A[i] < sum) back--;
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	TwoPointers();

	cout << ans;
}