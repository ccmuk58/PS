#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    // 막은 적을 내림차순으로 저장
	priority_queue<int> pq;
    
	while(answer < enemy.size())
	{
		pq.push(enemy[answer]);
		n -= enemy[answer];
        
        // 막은 후 체력 0이상이면 다음 라운드로
		if(n>=0)
        {
		    ++answer;
            continue;            
        }
        // 0보다 작은데 무적권 없으면 gameover
        else if(k<=0) 
        {
            return answer;
        }
        // 무적권으로 지난 라운드 중 가장 큰 라운드 무적 처리
        else
        {
            --k;
            n += pq.top();
            pq.pop();
            ++answer;   
        }
	}
    return answer;
}