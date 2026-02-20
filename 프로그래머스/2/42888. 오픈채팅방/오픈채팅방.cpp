#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> userList;
    vector<pair<string, string>> userLog;
    
    for (int i = 0; i < record.size(); i++) {
        int index = 0;
        char type = record[i][0];
        while(record[i][index] != ' ') 
            index++;
        index++;
        
        string userId = "";
        while(index < record[i].size() && record[i][index] != ' ')
            userId += record[i][index++];
        
        if (type == 'E') {
            index++;
            string userName = "";
            while(index < record[i].size() && record[i][index] != ' ')
                userName += record[i][index++];
            userList[userId] = userName;
            userLog.push_back({userId, "님이 들어왔습니다."});
        }
        else if (type == 'L') {
            userLog.push_back({userId, "님이 나갔습니다."});
        }
        else {
            index++;
            string userName = "";
            while(index < record[i].size() && record[i][index] != ' ')
                userName += record[i][index++];
            userList[userId] = userName;
        }
    }
    
    vector<string> answer;
    for (int i = 0; i < userLog.size(); i++)
        answer.push_back(userList[userLog[i].first] + userLog[i].second);
    
    return answer;
}