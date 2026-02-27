#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<int> stack(numbers.size());
    int top = -1;
    for (int i = 0; i < numbers.size(); i++) {
        while (top != -1 && numbers[stack[top]] < numbers[i]) {
            answer[stack[top]] = numbers[i];
            top--;
        }
        stack[++top] = i;
    }
    return answer;
}