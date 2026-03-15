#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isInside(int y, int x, vector<string>& board) {
    return (y >= 0 && y < board.size() && x >= 0 && x < board[0].size());
}

int bfs(int y, int x, vector<string> board) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = true;
    
    int mY[4] = {0, 0, -1, 1};
    int mX[4] = {1, -1, 0, 0};
    
    int count = 0; 
    while(!q.empty()) {
        int currY = q.front().first.first;   
        int currX = q.front().first.second;
        int currCnt = q.front().second;
        q.pop();
        
        if (board[currY][currX] == 'G')
            return currCnt;
        
        for (int i = 0; i < 4; i++) {
            int nextY = currY + mY[i];
            int nextX = currX + mX[i];
            if (isInside(nextY, nextX, board) &&
               board[nextY][nextX] != 'D') {
                while(isInside(nextY, nextX, board) && board[nextY][nextX] != 'D') {
                    nextY += mY[i];
                    nextX += mX[i];
                }
                if (visited[nextY - mY[i]][nextX - mX[i]] == true)
                    continue;
                q.push({{nextY - mY[i], nextX - mX[i]}, currCnt + 1});
                visited[nextY - mY[i]][nextX - mX[i]] = true;
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (board[i][j] == 'R')
                return bfs(i, j, board);
}