#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    for (int i = 0; i < topping.size(); i++)
        right[topping[i]]++;
    
    int count = 0;
    for (int i = 0; i < topping.size(); i++) {
        int current = topping[i];
        left[current]++;
        right[current]--;
        
        if (right[current] == 0)
            right.erase(current);
        if (left.size() == right.size())
            count++;
    }
    
    return count;
}