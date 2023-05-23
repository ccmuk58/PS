#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
using namespace std;
constexpr int LIMIT = 10000;
constexpr long long LENGTH = 60;
long long shell[LIMIT] = {};
long long mergeShell[LENGTH] = {};

long long getShiftedNumber(long long num, int shift)
{
	bool carry = false;
	shift %= LENGTH;
	for (int i = 0; i < shift; i++)
	{
		if (num & 1LL) carry = true;
		num = num >> 1LL;
		if (carry) num |= (1LL<<(LENGTH-1LL));
		carry = false;
	}

	return num;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M, L;
	int count = 0;
	string pattern;
	int P = 0, D = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> L >> pattern;
		for (int k = 0; k < LENGTH; k += pattern.length()) {
			for (int j = 0; j < pattern.length(); j++)
			{
				if (pattern[j] == '1') shell[i] |= (1LL << (j+k));
			}
		}
	}
	for (int i = 0; i < LENGTH; i++)
	{
		mergeShell[i] = shell[0];
		for (int j = 1; j < N; j++)
		{
			mergeShell[i] &= getShiftedNumber(shell[j], (i * (j)));
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> P >> D;
		int firstPos = P + D;
		P %= LENGTH;
		D %= LENGTH;
		firstPos %= LENGTH;
		if (firstPos < 0) firstPos = LENGTH + firstPos;
		if (P < 0) P = LENGTH + P;
		if (D < 0) D = LENGTH + D;

		if (mergeShell[D] & (1LL << firstPos)) {
			count++;
		}
	}
	cout << count;
}