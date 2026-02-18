#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int start, int n, vector<vector<int>>& map, vector<bool>& visited) {
    visited[start] = true;
    int count = 1;
    for (int i = 1; i <= n; i++)
        if (!visited[i] && map[start][i] == 1)
            count += dfs(i, n, map, visited);
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
        for (int j = 0; j < wires.size(); j++) {
            if (i == j)
                continue;
            map[wires[j][0]][wires[j][1]] = 1;
            map[wires[j][1]][wires[j][0]] = 1;
        }
        vector<bool> visited(n + 1, false);
        int result = dfs(1, n, map, visited);   
        answer = min(answer, abs(result - (n - result)));
    }
    return answer;
}