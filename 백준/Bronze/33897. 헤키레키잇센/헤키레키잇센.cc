#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	int mxlen=0;
	int len=0;
	int cnt=1;
	vector<int> v(300002);
	for(int i=0; i<N; i++)
	{

		cin >> A;
		if(A>=v[len])
		{
			len++;
		}
		else{
			len = 1;
			cnt++;
		}
		mxlen = max(len,mxlen);
		v[len]=A;
	}

	cout << cnt << " " << mxlen;

}