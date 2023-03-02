#include <iostream>
#include <algorithm>
using namespace std;
constexpr int LIMIT = 102;

int N, M;
int basket[LIMIT];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		basket[i] = i;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		swap(basket[a], basket[b]);
	}

	for (int i = 1; i <= N; i++)
		cout << basket[i] << " ";
}