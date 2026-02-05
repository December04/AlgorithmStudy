#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    set<char> isUsed;
    for (int i = 0; i < skill.length(); i++)
        isUsed.insert(skill[i]);
    
    int count = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        int skillIdx = 0;
        bool isOk = true;
        for (int j = 0; j < skill_trees[i].length(); j++)
            if (isUsed.find(skill_trees[i][j]) != isUsed.end())
                if (skill_trees[i][j] == skill[skillIdx]) {
                    skillIdx++;
                }
                else {
                    isOk = false;
                    break;
                }   
        if (isOk == true)
            count++;
    }
    return count;
}