#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
using pdp = pair<double, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
constexpr int LMT = 1e6 + 2;
constexpr ll MOD = 1'000'000'007;
ll A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
	
	string s, t;
	int a, b;
	cin >> N;
	cin >> s >> t;
	cin >> a >> b;

	char ca = s[a];
	char cb = s[b];
	s.erase(a, 1);
	s.erase(b-1, 1);

	int ai = N-2;
	for(int i=0; i<N-2; i++)
	{
		if(s[i]!=t[i])
		{
			ai = i;
			break;
		}
	}

	for(int i=ai-1; i>=0; i--)
	{
		if(ca!=s[i])
		{
			ai = i+1;
			s.insert(s.begin()+ai, ca);
			break;
		}
	}
	if(s.length() == t.length()-2)
	{
		ai = 0;
		s.insert(s.begin(), ca);
	}

	for(int i=ai+1; i<N-1; i++)
	{
		if(s[i]!=t[i])
		{
			s.insert(s.begin()+i, cb);
			break;
		}
	}
	if(s.length()<t.length())
		s.insert(s.end() ,cb);

	if(s==t) cout << "YES";
	else cout << "NO";


}