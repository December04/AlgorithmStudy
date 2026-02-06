#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    for (int i = 0; i < bridge_length; i++)
        bridge.push(0);
    
    int totalWeight = 0;
    int waitIdx = 0;
    int count = 0;
    while(waitIdx < truck_weights.size()) {
        int arrived = bridge.front();
        totalWeight -= arrived;
        bridge.pop();
        int next = truck_weights[waitIdx];
        if (totalWeight + next <= weight) {
            bridge.push(next);
            totalWeight += next;
            waitIdx++;
        }
        else
        {
            bridge.push(0);
        }
        count++;
    }
    
    return count + bridge_length;
}