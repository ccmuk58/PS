#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using pip = pair<int, pi>;
const int LMT = 1000;
const int dy[] = {0,0, 1, -1};
const int dx[] = {1,-1, 0, 0};

int N, M;
int p[LMT*LMT+2] = {};
ll h[LMT+2][LMT+2]={};
ll t[LMT+2][LMT+2]={};
ll ts[LMT*LMT+2]={};
ll ans[LMT+2][LMT+2]={};

int find(int n)
{
	if(p[n]==n)return n;
	return p[n] = find(p[n]);
}
void uni(pi ap, pi bp)
{
	int ay = ap.first;
	int ax = ap.second;
	int by = bp.first;
	int bx = bp.second;

	int a = find(ay*M+ax);
	int b = find(by*M+bx);
	
	if(a==b) return;

	if(ts[a] < ts[b])
		swap(a,b);
	p[b] = a;
	ts[a] += ts[b];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
	
	iota(p+1, p+N*M+1, 1);
	vector<pip> v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
			cin >> h[i][j];
			v.push_back({h[i][j],{i,j}});
        }
    }
	sort(v.begin(),v.end());
	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
			cin >> t[i][j];
			ts[i*M+j]=t[i][j];
        }
    }

	int i=0;
	while(i<v.size())
	{
		queue<pi> q;
		queue<pi> pos;
		q.push(v[i].second);
		pos.push(v[i].second);
		i++;
		while(i<v.size() && h[q.front().first][q.front().second] == v[i].first)
		{
			q.push(v[i].second);
			pos.push(v[i].second);
			i++;
		}
		while(!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			int ch = h[y][x];
			q.pop();
			for(int k=0; k<4; k++)
			{
				int ny=y+dy[k];
				int nx=x+dx[k];

				if(ny<0 || ny>=N || nx < 0 || nx>=M)continue;

				if(ch >= h[ny][nx] && find(ny*M+nx) != find(y*M+x))
				{
						uni({ny,nx},{y,x});
						q.push({ny,nx});
				}
			}
		}
		while(!pos.empty())
		{
			pi p = pos.front();
			pos.pop();
			ans[p.first][p.second] = ts[find(p.first*M+p.second)];
		}
		
	}

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}