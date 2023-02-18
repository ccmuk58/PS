#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
constexpr int LIMIT = 32;

int T;
string s[LIMIT];

int Palindrome(const string& s, int front, int back, int cnt)
{
	if (cnt > 1) return 2;
	while (front < back)
	{
		if (s[front] != s[back])
		{
			cnt++;
			if (Palindrome(s, front + 1, back, cnt) == 0 || Palindrome(s, front, back - 1, cnt) == 0)
				return 1;
			else return 2;
		}
		else {
			front++;
			back--;
		}
	}
	return 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> s[i];
		int ans = Palindrome(s[i], 0, s[i].length() - 1, 0);
		cout << ans << "\n";
	}
}