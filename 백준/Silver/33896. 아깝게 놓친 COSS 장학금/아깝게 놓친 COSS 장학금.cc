#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;
using pip = pair<int, pi>;
constexpr int dy[] = {0, 0, -1, +1};
constexpr int dx[] = {-1, +1, 0, 0};
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;

struct Student{
	string name;
	int score;
	int risk;
	int cost;
	int ans;
};

bool cmp(Student a ,Student b){
	if(a.ans != b.ans) return a.ans > b.ans;
	else if(a.cost != b.cost) return a.cost < b.cost;
	return a.name < b.name;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	vector<Student> v;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string name;
		int score;
		int risk;
		int cost;
		cin >> name >> score >> risk >> cost;

		Student s;
		s.name=name;
		s.score=score;
		s.risk=risk;
		s.cost=cost;
		s.ans=(score*score*score)/(cost*(risk+1));
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	cout << v[1].name;

}