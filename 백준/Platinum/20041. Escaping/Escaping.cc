#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1, -1, -1, 1, 1};
constexpr int dx[] = {-1, +1, 0, 0, -1, 1, -1, 1};
constexpr int LMT = 1e6 + 2;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

	vector<pi> v;
	for(int i=0; i<N; i++)
	{
		cin >> A >> B;
		v.push_back({A,B});
	}
	int x,y;
	cin >> x >> y;
	bool urdl[4]={};

	

	for(int i=0; i<N; i++)
	{
		v[i].first-=x;
		v[i].second-=y;

		int cx = v[i].first;
		int cy = v[i].second;
		if(cx==0)
		{
			if(cy<0)
			{
				urdl[2]=true;
			}
			else
			{
				urdl[0]=true;
			}
		}
		else if(cy==0)
		{
			if(cx<0)
			{
				urdl[3]=true;
			}
			else
			{
				urdl[1]=true;
			}
		}
		else if(abs(cx)==abs(cy))
		{
			if(cx>0)
			{
				if(cy>0)
				{
					urdl[0]=true;
					urdl[1]=true;
				}
				else
				{
					urdl[1]=true;
					urdl[2]=true;
				}
			}
			else
			{
				if(cy>0)
				{
					urdl[0]=true;
					urdl[3]=true;
				}
				else
				{
					urdl[3]=true;
					urdl[2]=true;
				}
			}
		}
		else if(abs(cx)<abs(cy))
		{
				if(cy>0)
				{
					urdl[0]=true;
				}
				else
				{
					urdl[2]=true;
				}
		}
		else
		{
				if(cx>0)
				{
					urdl[1]=true;
				}
				else
				{
					urdl[3]=true;
				}
		}
	}

	for(int i=0; i<4; i++)
	{
		if(!urdl[i])
		{
			cout << "YES";
			return 0;
		}
	}
		cout << "NO";
}