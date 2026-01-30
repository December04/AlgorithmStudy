#include <vector>

using namespace std;

int solution(int n) {
    vector<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    if (n <= 2)
        return arr[n - 1];
    for (int i = 3; i <= n; i++) {
        arr[2] = arr[0] + arr[1];
        if (arr[2] >  1000000007)
            arr[2] = arr[2] % 1000000007;
        arr[0] = arr[1];
        arr[1] = arr[2];
    }
    
    return arr[2];
}