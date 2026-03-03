#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    queue<int> serverList;
    for (int i = 0; i < k; i++)
        serverList.push(0);
    int answer = 0;
    int serverCount = 0;
    for (int i = 0; i < players.size(); i++) {
        serverCount -= serverList.front();
        serverList.pop();
        int needServer = (players[i] / m);
        if (needServer - serverCount > 0) {
            serverList.push(needServer - serverCount);
            answer += needServer - serverCount;
            serverCount += needServer - serverCount;
        }
        else 
            serverList.push(0);
    }
    return answer;
}