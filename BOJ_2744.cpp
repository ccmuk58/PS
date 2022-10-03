#include <iostream>
using namespace std;
int main() {
	
	char s[128];

	cin >> s;
	for(int i=0; i<128; i++)
	{
		if(s[i]=='\0') break;
		else if((int)s[i] <= 90) s[i] += 32;
		else s[i] -= 32;
	}
	cout << s;
}