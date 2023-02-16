#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
constexpr int LIMIT = 4002;

int n;
int A[LIMIT];
int B[LIMIT];
int C[LIMIT];
int D[LIMIT];
ll ans;
vector<int> AB;
vector<int> CD;


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	AB.reserve(n * n);
	CD.reserve(n * n);

	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	for (const auto& ab : AB)
	{
		int lb = lower_bound(CD.begin(), CD.end(), -ab) - CD.begin();
		int ub = upper_bound(CD.begin(), CD.end(), -ab) - CD.begin();
		ans += ub - lb;
	}
	cout << ans;
}
