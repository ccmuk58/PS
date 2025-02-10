#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using ll = long long;
using pl = pair<ll, ll>;
constexpr int LIMIT = 1e5 + 2;


int A, B, C;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> A >> B >> C;
	cout << A + B - C << "\n";
	cout << stoi(to_string(A) + to_string(B)) - C << "\n";

}