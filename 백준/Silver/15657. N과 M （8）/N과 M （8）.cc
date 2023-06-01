#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 10;
int N, M;
int arr[LIMIT];
int seq[LIMIT];

void func(int lastIdx, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = lastIdx; i < N; i++)
	{
		seq[len] = arr[i];
		func(i, len + 1);
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);
	func(0, 0);
}