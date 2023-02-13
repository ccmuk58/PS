#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
	int x, y;
 
	while (1) {
		cin >> x >> y;
 
		if (x == 0 && y == 0) {
			break;
		}
 
		if (x > y) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
 
	return 0;
}