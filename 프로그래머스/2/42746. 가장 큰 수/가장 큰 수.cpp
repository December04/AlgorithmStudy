#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numStr;
    for (int i = 0; i < numbers.size(); i++)
        numStr.push_back(to_string(numbers[i]));
    sort(numStr.begin(), numStr.end(), compare);
    for (int i = 0; i < numStr.size(); i++)
        answer += numStr[i];
    if (answer[0] == '0')
        return "0";
    return answer;
}