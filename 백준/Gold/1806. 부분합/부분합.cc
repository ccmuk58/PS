#include <bits/stdc++.h>
using namespace std;
int n, s;
int v[100002];
int curSum;
int minLen;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> s;
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	int left = 0;
	int right = 0;
	curSum = v[0];
	minLen = INT32_MAX;

	while(left <= right && right < n)
	{
		if(curSum < s)
		{
			right++;
			curSum += v[right];
		}
		else
		{
			minLen = min(minLen, right-left+1);
			curSum -= v[left];
			left++;
		}
	}
	if(left==0) minLen = 0;
	cout << minLen;
}
