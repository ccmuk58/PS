#include <iostream>
#include <algorithm>
using namespace std;

struct CTime{
	int start, end;
};

bool comparison(CTime t1, CTime t2){
	if(t1.end < t2.end)
		return true;
	else if(t1.end == t2.end)
		return t1.start < t2.start;
	else
		return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	CTime conference[n];

	for(int i=0; i<n; i++)
		cin >> conference[i].start >> conference[i].end;
	
	stable_sort(conference, conference+n, comparison);
	
	int minEndIdx=0, count=1;

	for(int i=1; i < n; i++){
		if(conference[minEndIdx].end <= conference[i].start){
			minEndIdx = i;
			count++;
		}
	}
	cout << count << "\n";
	
}