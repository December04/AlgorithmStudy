#include <vector>
#include <queue>
using namespace std;

struct Node {
  int y, x, count;  
};

bool isInside(int mapX, int mapY, int x, int y) {
    return (x >= 0 && (x < mapX) && y >= 0 && (y < mapY));
}

int bfs(vector<vector<int> > maps) {
    int mapX = maps[0].size();
    int mapY = maps.size();
    
    vector<vector<bool>> visited(mapY, vector<bool>(mapX, false));
    queue<Node> q;
    
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    int moveX[4] = {0, 0, -1, 1};
    int moveY[4] = {1, -1, 0, 0};
    while(!q.empty()) {
        Node curr = q.front();
        q.pop();
        
        if (curr.x == mapX - 1 && curr.y == mapY - 1)
            return curr.count; 
        
        for (int i = 0; i < 4; i++) {
            int nextX = curr.x + moveX[i];
            int nextY = curr.y + moveY[i];
            
            if (isInside(mapX, mapY, nextX, nextY))  {
                if (maps[nextY][nextX] == 1 && !visited[nextY][nextX]) { 
                    visited[nextY][nextX] = true;
                    q.push({nextY, nextX, curr.count + 1});
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int result = bfs(maps);
    
    return result;
}