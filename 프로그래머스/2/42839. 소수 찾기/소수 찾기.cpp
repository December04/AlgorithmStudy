#include <string>
#include <vector>
#include <set>

using namespace std;

int count;
string numList;
vector<bool> isUsed;
set<int> finded;

bool isPrime(int n) {
    if (n <= 1) 
        return false;
    if (n == 2) 
        return true;  
    if (n % 2 == 0) 
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) 
            return false;
    return true;
}

void dfs(string currNum) {
    if (currNum != "") {
        int currNumInt = stoi(currNum);
        if (isPrime(currNumInt) && finded.find(currNumInt) == finded.end()) {
            finded.insert(currNumInt);
            count++;
        }
    }
    if (currNum.length() == numList.length())
        return;
    for (int i = 0; i < numList.length(); i++)
        if (!isUsed[i]) {
            isUsed[i] = true;
            dfs(currNum + numList[i]);
            isUsed[i] = false;
        }
}

int solution(string num) {
    count = 0;
    numList = num;
    isUsed.assign(num.length(), false);
    finded.clear();
    dfs("");
    return count;
}