#include <iostream>
#include <algorithm>
using namespace std;
constexpr int LIMIT = 102;

int w, h;

bool isWest(pair<int, int> curX)
{
    return (curX.first == 0 && curX.second < h);
}
bool isNorth(pair<int, int> curX)
{
    return (curX.first < w && curX.second == h);
}
bool isEast(pair<int, int> curX)
{
    return (curX.first == w && curX.second > 0);
}
bool isSouth(pair<int, int> curX)
{
    return (curX.first > 0 && curX.second == 0);
}


int getClockwiseCost(pair<int, int> curX, const pair<int, int>& target, int cost = 0) {
    if (curX == target) return cost;
    else if (isWest(curX)) curX.second += 1;
    else if (isNorth(curX)) curX.first += 1;
    else if (isEast(curX)) curX.second -= 1;
    else if (isSouth(curX)) curX.first -= 1;
    return getClockwiseCost(curX, target, cost + 1);
}

int getMinCost(const pair<int, int>& curX, const pair<int, int>& target) {
    int round = w*2 + h*2;
	int clockwiseCost = getClockwiseCost(curX, target);
	int cost = min(clockwiseCost, round - clockwiseCost);
    return cost;
}

// pair<x, y> 형태로 변환
void convertPosition(pair<int, int>& pos) {
    switch (pos.first) {
		// North
		case 1:
			pos.first = pos.second;
            pos.second = h;
            break;
		// South
        case 2:
			pos.first = pos.second;
            pos.second = 0;
            break;
		// West
        case 3:
			pos.first = 0;
			pos.second = h - pos.second;
			break;
		// East
        case 4:
			pos.first = w;
			pos.second = h - pos.second;
			break;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int storeCnt;
    int sum = 0;
    pair<int, int> store[LIMIT];
    pair<int, int> X;
    cin >> w >> h >> storeCnt;

	int x, y;
    for (int i = 0; i < storeCnt; i++) {
        cin >> x >> y;
		store[i] = make_pair(x, y);
		convertPosition(store[i]);
    }
    cin >> x >> y;
	X = make_pair(x, y);
	convertPosition(X);

    for (int i = 0; i < storeCnt; i++) 
		sum += getMinCost(X, store[i]);
    cout << sum;
}