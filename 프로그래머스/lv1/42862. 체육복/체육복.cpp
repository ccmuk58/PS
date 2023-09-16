#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 1 ~ n
    vector<int> student(n+2);
    
    for(size_t i=1; i<=n; i++)
        student[i] = 1;

    for(size_t i=0; i<lost.size(); i++)
        student[lost[i]]--;
    
    for(size_t i=0; i<reserve.size(); i++)
        student[reserve[i]]++;
    
    for(size_t i=1; i<=n; i++)
    {
        if(student[i] == 0)
        {
            for(int nIdx = i-1 ; nIdx <= i+1; nIdx+=2)
            {
                if(student[nIdx] > 1)
                {
                    student[nIdx]--;
                    student[i]++;
                    break;
                }    
            }
        }
        
        if(student[i]>0) answer++;
    }
    return answer;
}