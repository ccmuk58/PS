#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
constexpr int LIMIT = 1000002;

int N;
stack<int> A, s, ans;

void solve()
{
	int a;
	while (!A.empty())
	{
		a = A.top();
		A.pop();

		while (!s.empty())
		{
			if (s.top() <= a)
			{
				s.pop();
			}
			else
			{
				ans.push(s.top());
				s.push(a);
				break;
			}
		}
		if (s.empty())
		{
			ans.push(-1);
			s.push(a);
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		A.push(n);
	}

	solve();

	while (!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
}
