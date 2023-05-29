#include <iostream>
#include <algorithm>
using namespace std;

bool comparison(int a, int b){
	return a > b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;	
	int sequence[n];
	for(int i=0; i<n; i++)
		cin >> sequence[i];
	
	sort(sequence, sequence+n, comparison);
	
	int result[n], count=0;
	int i;
	
	for(i=0; i<n; i++){
		if(sequence[i]<0 && sequence[i+1]<0){
			break;
		}
		else if(sequence[i]*sequence[i+1] > sequence[i]+sequence[i+1]){
			result[count++] = sequence[i]*sequence[i+1];
			i++;
		}
		else{
			result[count++] = sequence[i];
		}
	}
	for(int j=n-1; j>=i; j--){
		if(sequence[j]*sequence[j-1] > sequence[j]+sequence[j-1]){
			result[count++] = sequence[j]*sequence[j-1];
			j--;
		}
		else{
			result[count++] = sequence[j];
		}
	}
	
	int sum=0;
	for(i=0; i<count; i++){
		sum+=result[i];
	}
	cout << sum << "\n";
}