#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 4e6 + 2;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int pn[4000002];
vector<int> v;
vector<int> ps;
int main(){
   cin.tie(0)->sync_with_stdio(0);

   cin >> N;
   for(int i=2; i<LIMIT; i++)
   {
      pn[i] = i;
   }

   for(int i=2; i<LIMIT; i++)
   {
      if(pn[i]==0) continue;
      for(int j=i*2; j<LIMIT; j+=i)
      {
         pn[j] = 0;
      }
   }
   for(int i=2; i<LIMIT; i++)
   {
      if(pn[i]!=0) 
         v.push_back(pn[i]);
   }
   ps.push_back(0);
      for(int i=1; i<=v.size(); i++)
   {
      ps.push_back(ps[i-1] + v[i-1]);
   }
   
   int a = 0;
   int b = 1;
   int ans=0;

   while(a<=b && b<ps.size())
   {
      int s = ps[b] - ps[a];
      if(a==b) s = ps[b];
      if(N==s)
      {
        //  cout << "a: " << ps[a] << ", b: "<< ps[b] << "\n";
         
         ans++;
         a++;
         b++;
      }
      else if(N>s)
      {
         b++;
      }
      else
      {
         a++;
      }
   }
   cout << ans;
   
}