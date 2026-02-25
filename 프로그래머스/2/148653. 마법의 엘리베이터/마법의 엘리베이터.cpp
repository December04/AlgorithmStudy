#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int count = 0;
    while(storey > 0) {
        int target = storey % 10;
        if (target < 5) 
            count += target;
        else if (target > 5) {
            count += (10 - target);
            storey += 10;
        }
        else {
            int next = ((storey/10) % 10);
            count += 5;
            if (next >= 5)
                storey += 10;
        }
        storey /= 10;
    }
    return count;
}