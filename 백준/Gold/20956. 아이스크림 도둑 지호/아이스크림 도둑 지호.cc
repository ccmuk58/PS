#include<bits/stdc++.h>
using namespace std;

using mapV = map<int, vector<int>>;
int N, M;
mapV mv;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	int eatCnt = 0;

	for (int i = 1; i <= N; i++)
	{
		int amount;
		cin >> amount;
		mv[amount].push_back(i);
	}

	int cnt = 0;
	int isChange = 1;
	int result = 0;
	for (mapV::reverse_iterator iter = mv.rbegin(); iter != mv.rend(); iter++)
	{
		int head = 0;
		int tail = iter->second.size()-1;
		for (int i = 0; i < iter->second.size(); i++)
		{
			if (cnt == M) return 0;
			if (isChange == 1)
				result = iter->second[head++];
			else
				result = iter->second[tail--];

			cout << result << "\n";
			cnt++;
			if (iter->first % 7 == 0) isChange *= -1;
			if (head > tail) break;
		}
	}
}
