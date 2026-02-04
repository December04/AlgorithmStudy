#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int max = 0;
            for (int k = 0; k < 4; k++)
                if (j != k && land[i - 1][k] > max)
                    max = land[i - 1][k];
            land[i][j] += max;
        }
    }
    
    int score = 0;
    for (int i = 0; i < 4; i++)
        if (land[land.size() - 1][i] > score)
            score = land[land.size() - 1][i];
    return score;
}