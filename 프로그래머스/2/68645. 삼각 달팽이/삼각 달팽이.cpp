#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    int x = -1, y = 0; 
    int num = 1;       
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i % 3 == 0)
                x++;
            else if (i % 3 == 1)
                y++;
            else {
                x--;
                y--;
            }
            board[x][y] = num++;
        }
    }
    vector<int> answer;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (board[i][j] != 0)
                answer.push_back(board[i][j]);
    
    return answer;
}