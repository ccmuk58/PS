#include<bits/stdc++.h>
using namespace std;


int A;
int arr[4];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N, A;
	cin >> N;
	vector<int> v;

	for(int i=0; i<N*3; i++)
	{
		cin >> A;
		v.push_back(A);
		arr[A]++;
	}


	int t = 0;
	if(arr[1]==N-1)
	{
		t=1;
	}
	else if(arr[2]==N-1)
	{
		t=2;
	}
	else
	{
		t=3;
	}
	
	int tt=0;
	if(arr[1]==N+1)
	{
		tt=1;
	}
	else if(arr[2]==N+1)
	{
		tt=2;
	}
	else
	{
		tt=3;
	}

	cout << t <<"\n";
	cout << tt <<"\n";
}