#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int findNumber(vector<int> array) {
    int num = array[0];
    for (int i = 1; i < array.size(); i++)
        num = gcd(num, array[i]);
    return num;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int numA = findNumber(arrayA);
    int numB = findNumber(arrayB);
    int resultA = 0;
    int resultB = 0;
    bool checkA = true;
    for (int x : arrayB)
        if (x % numA == 0) {
            checkA = false;
            break;
        }
    if (checkA) 
        resultA = numA;
    bool checkB = true;
    for (int x : arrayA)
        if (x % numB == 0) {
            checkB = false;
            break;
        }
    if (checkB) 
        resultB = numB;
    if (resultA == 1) 
        resultA = 0;
    if (resultB == 1) 
        resultB = 0;
    return max(resultA, resultB);
}