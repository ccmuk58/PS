#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
constexpr int LIMIT = 100002;

// key : current_id, value : parent_id
map<string, string> m_parent;
// key : root_id, value : count
map<string, int> cnt;

void Init(string id)
{
	if (cnt[id]) return;
	m_parent[id] = id;
	cnt[id] = 1;
}
string Find(string id)
{
	if (m_parent[id] == id) return id;

	return m_parent[id] = Find(m_parent[id]);
}
void Union(string a, string b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	if (cnt[a] > cnt[b])
		swap(a, b);

	cnt[b] += cnt[a];
	m_parent[a] = b;
}
void PrintCnt(string id)
{
	id = Find(id);
	cout << cnt[id] << "\n";
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int T, F;
	string a, b;

	cin >> T;
	while (T--)
	{
		cin >> F;
		while (F--)
		{
			cin >> a >> b;
			Init(a);
			Init(b);
			Union(a, b);
			PrintCnt(a);
		}
		m_parent.clear();
		cnt.clear();
	}
}