#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	long long n;
	int cnt;
};
long long A, B;
int ans = -1;

void BFS()
{
	queue<Node> q;
	q.push({ A, 1 });

	while (!q.empty())
	{
		auto [n, cnt] = q.front();
		q.pop();

		if (n == B)
		{
			ans = cnt;
			return;
		}

		long long nn;
		nn = n * 2;
		if (nn <= B)
				q.push({ nn, cnt + 1 });

		nn = n * 10 + 1;
		if (nn <= B)
				q.push({ nn, cnt + 1 });
	}
}

int main()
{
	cin >> A >> B;

	BFS();

	cout << ans;
}