#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = 0; i < number.length(); i++) {
        while(!answer.empty() && answer.back() < number[i] && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    if (k > 0) {
        for (int i = k; i > 0; i--)
            answer.pop_back();
    }
    
    return answer;
}