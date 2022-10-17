#include <iostream>
#include <map>
using namespace std;
#define SIZE 1000002

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, N, M, num;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        map<int, int> m;
        for (int j = 0; j < N; j++) {
            cin >> num;
            m[num] = 1;
        }
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> num;
            if (m[num] == 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
}