#include<iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 1000000;

int N, K;
int g, x;
int ice[LIMIT+2];
int ans, sum;

void SlidingWindow()
{
	int head = 0;
	int tail = K * 2;
	if (tail >= LIMIT)
	{
		for (const auto& i : ice)
		{
			sum += i;
		}

		ans = sum;
		return;
	}

	for (int i = head; i <= tail; i++) 
	{
		sum += ice[i];
	}
	ans = sum;

	while (tail < LIMIT)
	{
		head++;
		tail++;

		sum -= ice[head-1];
		sum += ice[tail];
		
		ans = max(ans, sum);
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> g >> x;
		ice[x] = g;
	}

	SlidingWindow();

	cout << ans;
}