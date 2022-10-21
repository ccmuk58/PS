#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	map<string, string, greater<>> m;
	map<string, string>::iterator iter;
	string name, state;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> name >> state;
		m[name] = state;
	}

	for(iter = m.begin(); iter!=m.end(); iter++){
		if(iter->second == "enter")
			cout << iter->first << "\n";
	}
}