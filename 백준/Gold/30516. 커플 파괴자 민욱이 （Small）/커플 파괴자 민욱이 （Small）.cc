#include <bits/stdc++.h>
using namespace std;

int n;
int group[1002] = {};
int soloCnt = 0;
int groupCnt = 1;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<int> v(n);

	// 입력
	cin >> v[0];
	group[groupCnt]++;
	for (int i=1; i<n; i++){
		cin >> v[i];
		if(v[i] == 0) soloCnt++;
		// 커플이 붙어있으면 그룹 나누기
		else if(v[i-1] == v[i]) groupCnt++;
		// 마지막 사람이 첫 번째 사람이랑 커플이면 그룹 나누기
		else if(i == n-1 && groupCnt == 2 && v[n-1] == v[0]) groupCnt++;
		// 그룹에 사람 추가
		group[groupCnt]++;
	}

	// 분리 안되는 경우 출력
	if(n == 2 && soloCnt == 0)
	{
		cout << -1;
		return 0;
	}

	// 그룹당 인원 출력
	cout << groupCnt << "\n";
	for(int i=1; i<=groupCnt; i++){
		cout << group[i] << " ";
	}
	cout << "\n";
	
	// 그룹 거꾸로 출력
	for(int i=groupCnt; i>0; i--)
		cout << i << " ";
}