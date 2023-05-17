#include <iostream>
#include <cmath>
using namespace std;

int primeNumber[1000002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n;
	cin >> m >> n;
	
	for(int i=2; i<=n; i++){
		primeNumber[i]=i;
	}
	
	for(int i=2; i<=sqrt(n); i++){
		if(primeNumber[i]==0){
			continue;
		}
			
		for(int j=i*i; j<=n; j+=i){
			primeNumber[j]=0;
		}
	}
	
	for(int i=m; i<=n; i++){
		if(primeNumber[i])
			cout << primeNumber[i] << "\n";
	}
	
}