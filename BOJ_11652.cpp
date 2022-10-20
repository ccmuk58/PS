#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	map<long long, int> m={};
	long long num, maxCount=0, maxNum=0;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> num;
		m[num]++;
		if(m[num]==maxCount && num < maxNum){
			maxCount = m[num];
			maxNum = num;
		}
		else if(m[num]>maxCount) {
			maxCount = m[num];
			maxNum = num;
		}
	}
	cout << maxNum;
}