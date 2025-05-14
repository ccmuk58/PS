#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int A,B,C,N,M,K,L, R;
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};
bool vstd[1002][1002]={};
int room[1002][1002]={};
int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> R >> C;

	for(int i=0; i<R; i++)
	{
		int cost;
		cin >> A >> B >> cost;
		room[A][B]=cost;
	}
	queue<pair<int,pi>> q;
	for(int i=0; i<C; i++)
	{
		cin >> A >> B;
		q.push({0, {A,B}});
		vstd[A][B] = true;
	}

	int ans = INT32_MAX;
	while(!q.empty())
	{
		int dis = q.front().first;
		int y =q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny<1||ny>N||nx<1||nx>M) continue;
			if(vstd[ny][nx]) continue;

			vstd[ny][nx]=true;
			if(room[ny][nx]>0) ans = min(ans,(dis+1)*room[ny][nx]);
			q.push({dis+1,{ny,nx}});
		}
	}
	cout << ans;

}