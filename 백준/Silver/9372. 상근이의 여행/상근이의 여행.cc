#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int T, N, M;
	int a, b;

	cin >> T;

	while(T--)
	{
		cin >> N >> M;

		for(int i=0; i<M; i++)
		{
			cin >> a >> b;
		}
		cout << N-1 << "\n";
	}
}