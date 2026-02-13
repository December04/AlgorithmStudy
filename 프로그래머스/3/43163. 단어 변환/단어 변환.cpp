#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isOneDiff(string a, string b) {
    int count = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) {
            count++;
            if (count >= 2)
                return false;
        }
    return true;
}

int bfs(int count, string begin, string target, vector<string> words) {
    queue<pair<int, string>> q;
    vector<bool> visited(words.size(), 0);
    q.push({count, begin});
    while(!q.empty()) {
        int currCount = q.front().first;
        string currStr = q.front().second; 
        if (currStr == target)
            return currCount;
        q.pop();
        for (int i = 0; i < words.size(); i++)
            if (!visited[i] && currStr != words[i] && isOneDiff(currStr, words[i])) {
                q.push({currCount + 1, words[i]});
                visited[i] = true;
            }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(0, begin, target, words);
    return answer;
}