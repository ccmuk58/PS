#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int lu[2] = {51, 51};
    int rb[2] = {-1, -1};;
    
    for (int y = 0; y < wallpaper.size(); y++)
    {
        for (int x = 0; x < wallpaper[y].length(); x++)
        {
            if (wallpaper[y][x] == '#')
            {
                lu[0] = min(lu[0], y);
                lu[1] = min(lu[1], x);
                rb[0] = max(rb[0], y);
                rb[1] = max(rb[1], x);
            }
        }
    }
    answer.push_back(lu[0]);
    answer.push_back(lu[1]);
    answer.push_back(rb[0]+1);
    answer.push_back(rb[1]+1);
    
    return answer;
}