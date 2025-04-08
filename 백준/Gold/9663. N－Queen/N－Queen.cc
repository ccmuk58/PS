#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int b[17];
ll ans;

/*
bool isPossible(int y, int x)
{
   for(int i=1; i<=y; i++)
      if(b[i][x]) return false;
   //for(int i=1; i<=x; i++)
   //   if(b[y][i]) return false;
   //for(int i=0; y+i<=N && x+i<=N; i++)
   //   if(b[y+i][x+i]) return false;
   //for(int i=1; y+i<=N && x-i>=1; i++)
   //   if(b[y+i][x-i]) return false;
   for(int i=1; y-i>=1 && x+i<=N; i++)
      if(b[y-i][x+i]) return false;
   for(int i=1; y-i>=1 && x-i>=1; i++)
      if(b[y-i][x-i]) return false;
   
   return true;
}
*/
bool isPossible(int y, int x)
{
	for(int i=y-1; i>=1; i--)
	{
		if(b[i]==x || b[i]==x-(y-i) || b[i]==x+(y-i)) return false;
	}
	return true;
}
void bt(int y)
{
   if(y==N)
   {
      ans++;
      return;
   }
	for(int j=1; j<=N; j++)
	{
		if(isPossible(y+1, j))
		{
			b[y+1] = j;
			bt(y+1);
			b[y+1] = -1;
		}
      }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);

   cin >> N;
   fill(b+1, b+N+1, -1);
    for (int i = 1; i <= N; i++)
    {
      b[1] = i;
      bt(1);
      b[1] = -1;
    }
   cout << ans;
}