#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<pair<int,int>>> graph (N + 1);
    for(int i = 0; i < road.size(); i++)
    {
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (cost > dist[now])
            continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int nextNode = graph[now][i].first;
            int nextCost = cost + graph[now][i].second;
            if (nextCost < dist[nextNode]) {
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++)
        if (dist[i] <= K)
            answer++;
    return answer;
}