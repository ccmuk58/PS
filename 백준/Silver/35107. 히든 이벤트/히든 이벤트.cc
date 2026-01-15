#include<bits/stdc++.h>
using namespace std;
using ll = long long;


double N, A, M , K;
double arr[200002];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	vector<int> v;

	double p = 0;
	arr[0] = M/N;
	cout << arr[0] << "\n";
	for(int i=1; i<K; i++)
	{
		arr[i] = arr[i-1]+(M-M*arr[i-1])/(N-i);
		
		arr[i]=min(1.0, arr[i]);
		cout << arr[i] << "\n";
	}
}