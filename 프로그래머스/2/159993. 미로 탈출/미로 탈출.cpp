#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(char process, int y, int x, vector<string> maps) {
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    queue<pair<pair<int,int>, int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = true;
    int moveY[4] = {0, 0, -1, 1};
    int moveX[4] = {1, -1, 0, 0};
    while(!q.empty()) {
        int currY = q.front().first.first;
        int currX = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if (maps[currY][currX] == process)
            return count;
        for (int i = 0; i < 4; i++) {
            int nextY = currY + moveY[i];
            int nextX = currX + moveX[i];
            if (nextY >= 0 && nextY < maps.size() && nextX >= 0 && nextX < maps[0].length())
                if (maps[nextY][nextX] != 'X' && !visited[nextY][nextX]) {
                    q.push({{nextY, nextX}, count + 1});
                    visited[nextY][nextX] = true;
                }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int startX, startY, leverX, leverY;
    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[0].length(); j++) {
            if (maps[i][j] == 'S') {
                startX = j;
                startY = i;
            }
            if (maps[i][j] == 'L') {
                leverX = j;
                leverY = i;
            }
        }
    int toLever = bfs('L', startY, startX, maps);
    if (toLever == -1)
        return -1;
    int toExit = bfs('E', leverY, leverX, maps);
    if (toExit == -1)
        return -1;
    return toLever + toExit;
}