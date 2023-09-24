#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

int solution(int n, int k, std::vector<int> enemy) {
    std::vector<int> buffer;
    buffer.reserve(enemy.size());
    std::make_heap(buffer.begin(), buffer.end());
    
    int answer = 0;
    int sum = 0;
    
    for (const auto i : enemy) {
        buffer.push_back(i);
        std::push_heap(buffer.begin(), buffer.end());
        
        sum += i;

        if (sum > n) {
            if(k<=0) return answer;
            std::pop_heap(buffer.begin(), buffer.end());
            sum -= buffer.back();
            buffer.pop_back();
            --k;
        }
        ++answer;
    }
    
    return answer;
}