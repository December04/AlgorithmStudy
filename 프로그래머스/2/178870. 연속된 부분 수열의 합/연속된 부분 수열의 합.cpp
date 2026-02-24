#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 0};
    int startIdx = 0;
    int endIdx = 0;
    int sum = 0;
    int minLength = sequence.size() + 1;
    
    while (endIdx < sequence.size()) {
        sum += sequence[endIdx];
        while(sum > k && startIdx < endIdx)
            sum -= sequence[startIdx++];
        if (sum == k) {
            int currLength = endIdx - startIdx + 1;
            if (currLength < minLength) {
                minLength = currLength;
                answer = {startIdx, endIdx};
            }
        }
        if (minLength == 1)
            break;
        endIdx++;
    }
    
    return answer;
}