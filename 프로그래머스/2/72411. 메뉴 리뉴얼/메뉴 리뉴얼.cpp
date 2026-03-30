#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

unordered_map<string, int> combination;

void dfs(int idx, string com, string order) {
    if (com.length() >= 2)
        combination[com]++;
    for (int i = idx; i < order.length(); i++)
            dfs(i + 1, com + order[i], order);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (string order : orders) {
        sort(order.begin(), order.end());
        dfs(0, "", order);
    }
    vector<string> answer;
    for (auto courseSize : course) {
        int mostOrdered = 0;
        for (auto menu : combination)
            if (menu.first.length() == courseSize)
                mostOrdered = max(mostOrdered, menu.second);
        if (mostOrdered < 2) 
            continue;
        for (auto menu : combination)
            if (menu.first.size() == courseSize && menu.second == mostOrdered)
                answer.push_back(menu.first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}