#include<bits/stdc++.h>
using namespace std;
constexpr int LIMIT = 1002;
int N, M;
int score[LIMIT][3];

void move()
{
	int moveCnt;
	if (M <= N)	moveCnt = M;
	else		moveCnt = N + (M % N);

	for (int i = 0; i < moveCnt; i++)
	{
		int firstMoveIdx = 0;
		int moveIdx = 2;

		if (score[0][0] > score[0][1])
			firstMoveIdx = 1;

		for (int j = 1; j < N; j++)
		{
			if (score[j][0] > score[j][1])
			{
				score[j - 1][moveIdx] = score[j][0];
				moveIdx = 0;
			}
			else
			{
				score[j - 1][moveIdx] = score[j][1];
				moveIdx = 1;
			}
		}
		score[N-1][moveIdx] = score[0][firstMoveIdx];
		score[0][firstMoveIdx] = score[0][2];
	}
	
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> score[i][0] >> score[i][1];

	move();

	for (int i = 0; i < N; i++)
	{
		if(score[i][0] < score[i][1])
			cout << score[i][0] << " " << score[i][1] << "\n";
		else
			cout << score[i][1] << " " << score[i][0] << "\n";
	}
}