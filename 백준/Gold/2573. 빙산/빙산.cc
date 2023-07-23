#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 300+2;
constexpr int INF = 1e9 + 7;
constexpr int dy[4] = {0,0,-1,1};
constexpr int dx[4] = {-1,1,0,0};

int N, M;
int graph[LIMIT][LIMIT];
int result;
bool IsDivide()
{
    bool visited[LIMIT][LIMIT] = {};
    queue<pi> q;

    int continentCnt = 0;
    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < M-1; ++j) {
            if(graph[i][j] > 0 && !visited[i][j])
            {
                if(continentCnt>0) return true;
                q.push({i, j});
                visited[i][j] = true;
                continentCnt++;
                while(!q.empty())
                {
                    auto& [x, y] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if(graph[nx][ny] > 0 && !visited[nx][ny])
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    if(continentCnt>1) return true;
    else if(continentCnt==0) {
        result = 0;
        return true;
    }
    else return false;

}
void Melt()
{
    int nGraph[LIMIT][LIMIT] = {};
    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < M-1; ++j) {
            int cnt=0;
            for (int k = 0; k < 4; ++k) {
                if(graph[i+dy[k]][j+dx[k]] == 0) cnt++;
            }
            nGraph[i][j] = graph[i][j] - cnt;
            if(nGraph[i][j] < 0) nGraph[i][j] = 0;
        }
    }

    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < M-1; ++j) {
            graph[i][j] = nGraph[i][j];
        }
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];
        }
    }

    while(!IsDivide())
    {
        Melt();
        result++;
    }
    cout << result;
}