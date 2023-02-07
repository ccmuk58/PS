#include <iostream>
using namespace std;
constexpr int LIMIT = 10;

int N, M;
int num[LIMIT];
bool visited[LIMIT];

void solve(int cnt) {
    if (cnt > M) {
        for (int i = 1; i <= M; i++) {
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
		visited[i] = true;
		num[cnt] = i;
		solve(cnt + 1);
		visited[i] = false;
	}
}

int main() {
    cin >> N >> M;
    solve(1);
}