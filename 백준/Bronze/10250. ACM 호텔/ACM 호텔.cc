#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;

int T, H, W, N;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while(T--)
	{
		cin >> H >> W >> N;
		int floor = N%H;
		if(floor==0) floor=H;
		int room = ceil((float)N/H);
		if (room==0) room=1;
		string roomStr;
		if(room < 10) roomStr = "0"+to_string(room);
		else roomStr = to_string(room);
		cout << floor << roomStr << "\n";
	}

}