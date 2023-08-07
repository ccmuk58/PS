#include <bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 50001;

struct Node {
    int idx;
    int dist;
};
int N;
vector<Node> tree[LIMIT];
bool visited[LIMIT];
int result[LIMIT];
int startNode;
int maxDistSum;

void Print()
{
    for (int i = 1; i <= N; i++)
        cout << result[i] << "\n";
}

void CheckLeaf(int idx, int distSum)
{
    if (distSum > maxDistSum)
    {
        maxDistSum = distSum;
        startNode = idx;
    }
}
void dfs(int idx, int distSum=0)
{
    CheckLeaf(idx, distSum);
    result[idx] = max(result[idx], distSum);

    for (int i = 0; i < tree[idx].size(); i++)
    {
        auto& [nIdx, dist] = tree[idx][i];
        if (visited[nIdx]) continue;
        visited[nIdx] = true;
        dfs(nIdx, distSum+dist);
    }
}

void SearchDistance()
{
    for (int i = 0; i < 2; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(startNode);
    }
}

void SearchFirstLeaf()
{
    visited[1] = true;
    dfs(1);
}

void MakeTree()
{
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        tree[from].push_back({to, dist });
        tree[to].push_back({from, dist });
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    MakeTree();
    SearchFirstLeaf();
    SearchDistance();
    Print();
}
