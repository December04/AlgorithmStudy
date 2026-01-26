#include <string>
#include <set>
using namespace std;

bool isInside(int y, int x) {
    return (x <= 5) && (x >= -5) && (y <= 5) && (y >= -5);
}

int solution(string dirs) {
    int x = 0; 
    int y = 0;
   
    set<pair<pair<int, int>, pair<int, int>>> visited;
    for (int i = 0; i < dirs.size(); i++) {
        int nx = x;
        int ny = y;
        
        if (dirs[i] == 'U')
            ny++;
        else if (dirs[i] == 'D')
            ny--;
        else if (dirs[i] == 'R')
            nx++;
        else if (dirs[i] == 'L')
            nx--;
        else 
            continue;
        
        if (isInside(ny, nx)) {
            pair<int, int> current = {x, y};
            pair<int, int> next = {nx, ny};
            
            if (current < next) 
                visited.insert({current, next});
            else 
                visited.insert({next, current});
            
            x = nx;
            y = ny;
        }
    }
    
    return visited.size();
}