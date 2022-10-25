#include <iostream>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
 
	int m = (a*60) + b + c;
	int hour = (m / 60) % 24;
	int minute = m % 60;
 
	cout << hour << " " << minute;
}