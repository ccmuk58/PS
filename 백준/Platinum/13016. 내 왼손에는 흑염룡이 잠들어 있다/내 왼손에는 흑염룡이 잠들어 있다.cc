#include <bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 50001;

struct Node {
    int idx;
    int dist;
};
int N;
vector<Node> graph[LIMIT];
bool visited[LIMIT];
int result[LIMIT];
int startNode;
int maxSum;

void dfs(int idx, int distSum=0)
{
    visited[idx] = true;
    if (distSum > maxSum)
    {
        maxSum = distSum;
        startNode = idx;
    }
    result[idx] = max(result[idx], distSum);
    for (int i = 0; i < graph[idx].size(); i++)
    {
        auto& [nIdx, dist] = graph[idx][i];
        if (visited[nIdx]) continue;
        visited[nIdx] = true;
        dfs(nIdx, distSum+dist);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].push_back({ to, dist });
        graph[to].push_back({ from, dist });
    }
    dfs(1);
    for (int i = 0; i < 2; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(startNode);
    }
    for (int i = 1; i <= N; i++)
        cout << result[i] << "\n";
}