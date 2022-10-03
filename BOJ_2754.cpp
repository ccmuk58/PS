#include<iostream>
using namespace std;
int main(){
	string score;
	cin >> score;
	if(!score.compare("A+")) cout << "4.3";
	else if(!score.compare("A0")) cout << "4.0";
	else if(!score.compare("A-")) cout << "3.7";
	else if(!score.compare("B+")) cout << "3.3";
	else if(!score.compare("B0")) cout << "3.0";
	else if(!score.compare("B-")) cout << "2.7";
	else if(!score.compare("C+")) cout << "2.3";
	else if(!score.compare("C0")) cout << "2.0";
	else if(!score.compare("C-")) cout << "1.7";
	else if(!score.compare("D+")) cout << "1.3";
	else if(!score.compare("D0")) cout << "1.0";
	else if(!score.compare("D-")) cout << "0.7";
	else if(!score.compare("F")) cout << "0.0";
	else return 0;
}