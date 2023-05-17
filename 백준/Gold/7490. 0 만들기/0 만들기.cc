#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int getSum(string expression) {
    int sum = 0;
    int partSum = 1;
    int sign = 1;
	bool isCal = false;
    for (int i = 1; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            partSum = partSum * 10 + (expression[++i] - '0');
        }
		else {
			isCal = true;
            sum += partSum * sign;
            if (expression[i] == '+') sign = 1;
            else if (expression[i] == '-')  sign = -1;
            partSum = (expression[++i] - '0');
        }
    }
	sum += partSum * sign;
	return sum;
}
void recursion(int N, int curNum = 1, string expression = "1") {
    if (N == curNum) {
		if(getSum(expression)==0) cout << expression << "\n";
        return;
    }
    int nextNum = curNum + 1;
    recursion(N, nextNum, expression + ' ' + to_string(nextNum));
    recursion(N, nextNum, expression + '+' + to_string(nextNum));
    recursion(N, nextNum, expression + '-' + to_string(nextNum));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

	int T, N;
	cin >> T;

	while(T--)
	{
		cin >> N;
	    recursion(N);
		cout << "\n";
	}
}