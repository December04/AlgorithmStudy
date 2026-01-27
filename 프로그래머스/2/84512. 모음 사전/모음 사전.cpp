#include <string>
#include <vector>

using namespace std;

string order; 
string target;
int count;
int answer;

void dfs (string start) {
    if (answer != 0) 
        return;
    if (start == target) {
        answer = count;
        return;   
    }
    if (start.length() >= 5)
        return;
    for (int i = 0; i < 5; i++) {
        count++;
        dfs(start + order[i]);
    }
}

int solution(string word) {
    order = "AEIOU";
    target = word;
    count = 0;
    answer = 0;
    
    dfs("");
    
    return answer;
}