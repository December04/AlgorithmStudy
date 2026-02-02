#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compareSize(const std::string& a, const std::string& b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<string> sub;
    
    string num = "";
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{')
            num = "";
        else if (isdigit(s[i]) || s[i] == ',')
            num += s[i];
        else if (s[i] == '}') {
            if (!num.empty()) {
                sub.push_back(num);
                num = "";
            }
            if (i + 1 < s.length() - 1 && s[i+1] == ',') 
                i++; 
        }
    }
    sort(sub.begin(), sub.end(), compareSize);
    vector<int> answer;
    set<int> check;
    for (string& temp : sub) {
        string num = "";
        for (char c : temp) {
            if (isdigit(c))
                num += c;
            else {
                if (!num.empty()) {
                    int afterNum = stoi(num);
                    if (check.find(afterNum) == check.end()) {
                        check.insert(afterNum);
                        answer.push_back(afterNum);
                    }
                    num = "";
                }
            }
        }
        if (!num.empty()) {
            int afterNum = stoi(num);
            if (check.find(afterNum) == check.end()) {
                check.insert(afterNum);
                answer.push_back(afterNum);
            }
        }
    }
    return answer;
}