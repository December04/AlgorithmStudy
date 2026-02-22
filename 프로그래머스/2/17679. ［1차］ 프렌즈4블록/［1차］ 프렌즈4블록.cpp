#include <string>
#include <vector>

using namespace std;

bool isSquare (int y, int x, vector<string> board) {
    return (board[y][x] == board[y - 1][x] && 
            board[y][x] == board[y][x + 1] &&
            board[y][x] == board[y - 1][x + 1]);
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true) {
        bool found = false;
        vector<vector<bool>> check (m, vector<bool>(n, true));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] != 'X')
                    if (i > 0 && j < n - 1 && isSquare(i, j, board)) {
                        check[i][j] = false;
                        check[i - 1][j] = false;
                        check[i][j + 1] = false;
                        check[i - 1][j + 1] = false;
                        found = true;
                    }
        if (!found)
            break;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (check[i][j] == false) {
                    board[i][j] = 'X';
                    answer++;
                }
        
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = m - 1; j >= 0; j--)
                if (board[j][i] != 'X') 
                    temp += board[j][i];
            for (int j = m - 1; j >= 0; j--) {
                int tempIdx = (m - 1) - j;
                if (tempIdx < temp.length())
                    board[j][i] = temp[tempIdx];
                else
                    board[j][i] = 'X';
            }
        }
    }
    return answer;
}