#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const string VALID = "valid";
const string INVALID = "invalid";
constexpr char X = 'X';
constexpr char O = 'O';

int countShape(const string& str, char shape)
{
	int cnt = 0;
	for (const char &c : str)
		if (c == shape) cnt++;

	return cnt;
}
void chceckRows(const string& board, string& completed, char shape)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i * 3] == shape && board[i * 3 + 1] == shape && board[i * 3 + 2] == shape)
			for (int j = 0; j < 3; j++)	completed[i * 3 + j] = shape;
	}
}
void checkColumns(const string& board, string& completed, char shape)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i] == shape && board[i + 3] == shape && board[i + 6] == shape)
			for (int j = 0; j < 3; j++)	completed[i + j * 3] = shape;
	}
}
void checkDiagonals(const string& board, string& completed, char shape)
{
	if (board[0] == shape && board[4] == shape && board[8] == shape) 
		for (int j = 0; j < 3; j++) completed[j * 4] = shape;

	if (board[2] == shape && board[4] == shape && board[6] == shape)
		for (int j = 0; j < 3; j++) completed[j*2 + 2] = shape;
}
string checkBoard(const string& board)
{
	string completed = "123456789";
	int xCnt = countShape(board, X);
	int oCnt = countShape(board, O);
	if (xCnt < oCnt || xCnt - oCnt > 1)	return INVALID;


	chceckRows(board, completed, X);
	chceckRows(board, completed, O);
	checkColumns(board, completed, X);
	checkColumns(board, completed, O);
	checkDiagonals(board, completed, X);
	checkDiagonals(board, completed, O);

	int xCompletedCnt = countShape(completed, X);
	int oCompletedCnt = countShape(completed, O);
	
	if (xCompletedCnt >= 3 && xCompletedCnt < 6 && oCompletedCnt == 0)
	{
		if (xCnt == oCnt)return INVALID;
		else return VALID;
	}
	else if (xCompletedCnt == 0 && oCompletedCnt >= 3 && oCompletedCnt < 6)
	{
		if (xCnt > oCnt)return INVALID;
		else return VALID;
	}
	else if (xCompletedCnt == 0 && oCompletedCnt == 0 && xCnt + oCnt == 9) return VALID;
	else return INVALID;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);

	string input;
	while (true)
	{
		cin >> input;
		if (input == "end") break;
		cout << checkBoard(input) << "\n";
	}
}