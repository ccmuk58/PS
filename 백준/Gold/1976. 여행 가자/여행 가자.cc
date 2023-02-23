#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N_LIMIT = 202;

int parent[N_LIMIT];
int N, M;

void Init(int n)
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}
int Find(int n)
{
	if (parent[n] == n) return n;

	return parent[n] = Find(parent[n]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	parent[a] = b;
}
void Solution()
{
	cin >> N >> M;
	Init(N);

	int num;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> num;
			if (num) Union(i, j);
		}
	}

	cin >> num;
	int root = Find(num);
	for (int i = 2; i <= M; i++)
	{
		cin >> num;
		if (root != Find(num))
		{
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	Solution();
}