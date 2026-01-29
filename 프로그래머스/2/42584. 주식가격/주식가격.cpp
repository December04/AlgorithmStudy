#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> stack(prices.size());
    int top = -1;
    
    vector<int> answer(prices.size());
    for (int i = 0; i < prices.size(); i++) {
        while(top > -1 && prices[stack[top]] > prices[i])
        {
            answer[stack[top]] = i - stack[top];
            top--;
        }
        stack[++top] = i;
    }
    
    while (top > -1) {
        answer[stack[top]] = prices.size() - 1 - stack[top];
        top--;
    }
    
    return answer;
}