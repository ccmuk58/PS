#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end());
    
    int lastE = 0;
    for(const auto& t : targets)
    {
        int s = t[0];
        int e = t[1];
        
        if(s >= lastE)
        {
            lastE = e;
            answer++;
        }
        else if(e <= lastE)
        {
            lastE = e;
        }
    }
    return answer;
}