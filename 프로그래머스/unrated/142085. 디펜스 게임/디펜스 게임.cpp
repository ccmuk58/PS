#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    	
	priority_queue<int> pq;
    
	while(answer < enemy.size())
	{
		pq.push(enemy[answer]);
		n -= enemy[answer];
		if(n<0)
		{
			if(k>0)
			{
				--k;
				n += pq.top();
				pq.pop();
			}
			else
			{
				return answer;
			}
		}
		++answer;
	}
    return answer;
}