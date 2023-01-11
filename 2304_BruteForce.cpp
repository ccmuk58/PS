#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define RANGE 1002	// const int , constexpr
using namespace std;

// ÁÖ¼® ÇÏ¸é ±Â
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, h;
	int sum = 0;
	int col[RANGE] = { 0 };
	pair<int, int> max = { 0,0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		col[l] = h;
		if (max.second < h) max = { l,h };
	}

	pair<int, int> maxCol = { 0,0 };
	for (int i = 0; i <= max.first; i++) {
		if (col[i] >= maxCol.second) {
			if (maxCol.second != 0)
				sum += maxCol.second * (i - maxCol.first);
			maxCol = { i, col[i] };
		}
	}
	maxCol = { RANGE-1,0 };
	for (int i = RANGE-1; i >= max.first; i--) {
		if (col[i] >= maxCol.second) {
			if (maxCol.second != 0)
				sum += maxCol.second * (maxCol.first - i);
			maxCol = { i, col[i] };
		}
	}
	sum += max.second;
	cout << sum;
}