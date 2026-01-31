#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> q (scoville.begin(), scoville.end());
    
    int count = 0;
    while(q.top() < K) {
        int minF = q.top();
        q.pop();
        
        if (q.size() == 0)
            return -1;
        
        int minS = q.top();
        q.pop();
        
        q.push(minF + (minS * 2));
        count++;
    }
    
    return count;
}