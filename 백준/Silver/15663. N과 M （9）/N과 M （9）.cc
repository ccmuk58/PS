#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 10;
int N, M;
int arr[LIMIT];
int seq[LIMIT];
bool isUse[LIMIT];
void func(int len)
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
	int lastNum = 0;
	for (int i = 0; i < N; i++)
	{
		if (isUse[i]) continue;
		if (lastNum == arr[i]) continue;
		isUse[i] = true;
		lastNum = arr[i];
		seq[len] = arr[i];
		func(len + 1);
		isUse[i] = false;
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	func(0);
}