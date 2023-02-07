#include <iostream>
#include<algorithm>
using namespace std;
constexpr int LIMIT = 10;

int N, M;
int arr[LIMIT];
int num[LIMIT];
bool visited[LIMIT];

void solve(int cnt) {
    if (cnt >= M) {
        for (int i = 0; i < M; i++)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		num[cnt] = arr[i];
		solve(cnt + 1);
		visited[i] = false;
	}
}

int main() {
    cin >> N >> M;
	for(int i=0; i<N; i++)
		cin >> arr[i];
		
	sort(arr, arr+N);
    solve(0);
}