#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	long long A, B;
	cin >> T;

	while(T--)
	{
		cin >> A >> B;

		if(A==1 || B==1)
		{
			cout << "YES\n";
			continue;
		}		
		long long C = A+B;


		if(C%2==0) cout << "NO\n";
		else cout << "YES\n";

	}
}