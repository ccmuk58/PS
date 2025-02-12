#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e3 + 2;
constexpr int dy[] = { 0,0,-1,+1 };
constexpr int dx[] = { -1,+1,0,0 };
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

struct node{
	int y;
	int x;
	int c;
};
int m[LIMIT][LIMIT];
bool visited[LIMIT][LIMIT];
int cost[LIMIT][LIMIT];
int sx, sy;
void bfs()
{
	queue<node> q;
	q.push({sy, sx});
	visited[sy][sx] = true;
	while(!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int c = q.front().c;
		q.pop();
		cost[y][x] = c;
		for(int i=0 ; i<4; i++)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];
			int nc = c+1;
			if(visited[ny][nx]) continue;
			if(m[ny][nx]==0) continue;
			visited[ny][nx]=true;
			q.push({ny, nx, nc});
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin >> m[i][j];
			if(m[i][j]==2)
			{
				sy = i;
				sx = j;
			}
		}
	}
	bfs();
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			if((i!=sy || j!=sx) && cost[i][j]==0 && m[i][j]!=0)
				cost[i][j]=-1;
			cout << cost[i][j] << " ";
		}
		cout << "\n";
	}

}
