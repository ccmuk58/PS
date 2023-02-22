#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Value
{
	string id;
	int cnt;
};

// key : current_id, value : {parent_id, count}
unordered_map<string, Value> m_parent;

void Init(string id)
{
	if (m_parent[id].cnt) return;
	m_parent[id].id = id;
	m_parent[id].cnt = 1;
}
string Find(string id)
{
	if (m_parent[id].id == id) return id;

	return m_parent[id].id = Find(m_parent[id].id);
}
void Union(string a, string b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	if (m_parent[a].cnt > m_parent[b].cnt)
		swap(a, b);

	m_parent[b].cnt += m_parent[a].cnt;
	m_parent[a].id = b;
}
void PrintCnt(string id)
{
	id = Find(id);
	cout << m_parent[id].cnt << "\n";
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
	}
}