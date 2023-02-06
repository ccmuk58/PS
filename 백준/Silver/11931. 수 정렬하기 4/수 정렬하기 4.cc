#include<iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 1000002;

int N;
int num[LIMIT];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N, greater<>());

	for (int i = 0; i < N; i++)
		cout << num[i] << "\n";
}