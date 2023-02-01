#include <iostream>
#include <algorithm>
using namespace std;
constexpr int RANGE = 9;

int t[RANGE];
int sum = 0;

void Search(){
	for (int i = 0; i < RANGE; i++) {
		for (int j = 0; j < RANGE; j++) {
			if (i == j) continue;
			if (sum - t[i] - t[j] != 100) continue;
			t[i] = 1000;
			t[j] = 1000;
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < RANGE; i++) 
	{
		cin >> t[i];
		sum += t[i];
	}

	Search();

	sort(t, t + RANGE);

	for (int i = 0; i < 7; i++)
		cout << t[i] << "\n";
}