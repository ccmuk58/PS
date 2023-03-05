#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
constexpr int LIMIT = 50002;
struct Info
{
	int place;
	int cost;
	int sum;
};
struct cmp {
	bool operator()(const Info &l, const Info &r) const {
		return l.sum > r.sum;
	}
};
vector<Info> v[LIMIT];
int table[LIMIT];
bool fin[LIMIT];
priority_queue<Info, vector<Info>, cmp> pq;
int N, M, ans;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;

	for (int i = 0; i < LIMIT; i++)
	{
		table[i] = 2000000000;
	}
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b, c, 0 });
		v[b].push_back({ a, c, 0 });
	}

	pq.push({ 1, 0, 0 });
	fin[1] = true;
	while (!pq.empty())
	{
		auto last = pq.top();
		fin[last.place] = true;
		if (last.place == N) {
			ans = last.sum;
			break;
		}
		pq.pop();

		auto curV = v[last.place];
		for (int i = 0; i < curV.size(); i++)
		{
			if (fin[curV[i].place]) continue;
			if (table[curV[i].place] <= last.sum + curV[i].cost) continue;

			table[curV[i].place] = last.sum + curV[i].cost;
			pq.push({ curV[i].place, curV[i].cost, table[curV[i].place] });
		}
	}
	cout << ans;
}