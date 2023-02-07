#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n;
	int remain;
	
	cin >> n;
	remain = n%5;
	
	if(remain == 0 || remain == 2) cout << "CY\n";
	else cout << "SK\n";
}