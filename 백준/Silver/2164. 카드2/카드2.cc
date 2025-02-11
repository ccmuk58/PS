#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;

int N;
deque<int> dq;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
	
	if(N==1)
	{
		cout << 1;
		return 0;
	}

	for(int i=1; i<=N; i++)
		dq.push_back(i);


	while(dq.size()!=1)
	{
		dq.pop_front();
		int t = dq.front();
		dq.pop_front();
		dq.push_back(t);
	}
	cout << dq.front();
}
