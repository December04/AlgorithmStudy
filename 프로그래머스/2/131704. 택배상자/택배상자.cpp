#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> order) {
    vector<int> subCon(order.size());
    vector<int> mainCon = order;
    sort(mainCon.begin(), mainCon.end());
    
    int subTop = -1;
    int mainTop = 0;
    
    int count = 0;
    for (int i = 0; i < order.size(); i++) {
        int target = order[i];
        
        while(true) {
            if (mainTop != mainCon.size() && mainCon[mainTop] == target) {
                mainTop++;
                count++;
                break;
            }
            else if (subTop != -1 && subCon[subTop] == target) {
                subTop--;
                count++;
                break;
            }
            else if (mainTop == mainCon.size() - 1 && 
                     target != mainCon[mainTop] && 
                     target != subCon[subTop]) {
                return count;
            }
            else {
                subCon[++subTop] = mainCon[mainTop++];
            }
        }
    }
    
    return count;
}