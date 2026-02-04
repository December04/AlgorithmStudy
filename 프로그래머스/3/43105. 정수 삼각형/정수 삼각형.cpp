#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++)
        for (int j = 0; j <= i; j++) {
            int left = 0;
            int right = 0;
            if (j > 0) 
                left = triangle[i - 1][j - 1];
            if (j < i) 
                right = triangle[i - 1][j];
            if (left > right)
                triangle[i][j] += left;
            else
                triangle[i][j] += right;
        }   
    int result = 0;
    for (int i = 0; i < triangle.size(); i++)
        if (triangle[triangle.size() - 1][i] > result)
            result = triangle[triangle.size() - 1][i]; 
    return result;
}