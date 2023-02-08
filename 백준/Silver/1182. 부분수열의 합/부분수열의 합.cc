#include<iostream>
using namespace std;
constexpr int LIMIT = 22;

int N, S;
int num[LIMIT];
int ans;

void BT(int idx, int sum)
{
	if (idx == N)
	{
		if (sum == S) ans++;
		return;
	}
	
	BT(idx+1, sum);
	BT(idx + 1, sum + num[idx]);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	BT(0, 0);

	if (S == 0) ans--;
	cout << ans;
}