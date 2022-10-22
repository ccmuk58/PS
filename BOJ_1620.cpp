#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<string, string, greater<>> m;
	map<string, string>::iterator iter;
	string site, password;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> site >> password;
		m[site] = password;
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m[site] << "\n";
	}
}