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

string s;
vector<pair<char,int>> v;
vector<pair<char,int>> ans;

void print()
{
	for(int j=0; j<ans.size(); j++)
	{
		cout << ans[j].first;
	}
	cout <<"\n";
}
void srt()
{	
	for(int q=ans.size()-1; q>=0; q--)
	{
		for(int w=0; w<q; w++)
		{
			if(ans[w].second > ans[w+1].second)
				swap(ans[w], ans[w+1]);
		}
	}
}
void find(int a)
{
	if(a>=ans.size())return;
	for(int i=0; i<v.size(); i++)
	{
		if(ans[a].second < v[i].second)
		{
			ans.push_back(v[i]);
			v.erase(v.begin()+i);
			srt();
			print();
			i--;
			if(ans.size()==s.length())
				return;
			find(a+1);
		}	
	}
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin >> s;

	for(int i=0; i<s.length(); i++)
	{
		v.push_back({s[i],i});
	}
	sort(v.begin(), v.end());

	
	while(true)
	{
		ans.push_back(v[0]);
		v.erase(v.begin());
		srt();
		print();	
		find(0);
		if(ans.size()==s.length())
			return 0;
	}
	
}