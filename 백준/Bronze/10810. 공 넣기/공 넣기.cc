#include <iostream>
using namespace std;
constexpr int LIMIT = 102;

int box[LIMIT];
int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    while (M--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        for (int o = i; o <= j; o++)
            box[o] = k;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << box[i] << " ";
    }
}