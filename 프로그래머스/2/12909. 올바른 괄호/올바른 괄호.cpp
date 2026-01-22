#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector<char> stack;
    int t = -1;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stack.push_back(s[i]);
            t++;
        }
        else {
            if (t >= 0 && stack[t] == '(')
                t--;
            else
                return false;
        }
    }
    
    if (t == -1)
        return true;
    else
        return false;
}