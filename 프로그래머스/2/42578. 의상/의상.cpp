#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    for (int i = 0; i < clothes.size(); i++) {
        map[clothes[i][1]]++;
    }
    
    int answer = 1;
    for (const auto& [key, value] : map) {
        answer *= (value + 1);
    }
    
    return answer - 1;
}