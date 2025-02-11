#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;

int N, M;
vector<int> cards;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        cards.push_back(c);
    }
    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int s = cards[i] + cards[j] + cards[k];
                if (s > maxSum == s <= M) 
					maxSum = s;
			}
        }
    }
	cout << maxSum;
}