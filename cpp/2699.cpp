#include<iostream>
#include<vector>

using namespace std;

const int inf = 2e9;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long path = dijkstra(n, edges, source, destination);
        if(path < target) return {};
        bool found = (path == target);
        for(auto& edge : edges){
            if(edge[2] > 0) continue;
            if(found){
                edge[2] = inf;
                continue;
            }
            edge[2] = 1;
            path = dijkstra(n, edges, source, destination);
            if(path <= target){
                found = true;
                edge[2] += target - path;
            }
        }
        return found ? edges : vector<vector<int>>{};
    }
private:
    long long dijkstra(int n, vector<vector<int>>& edges, int src, int dest){
        vector<vector<int>> graph(n, vector<int>(n, inf));
        vector<int> dist(n, inf);
        vector<bool> visited(n, false);
        dist[src] = 0;
        for(auto &edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(w == -1) continue;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        for(int i = 0; i < n; i++){
            int u = -1;
            for(int v = 0; v < n; v++){
                if(!visited[v] && (u == -1 || dist[v] < dist[u]))
                    u = v;
            }
            visited[u] = true;
            for(int v = 0; v < n; v++){
                if(graph[u][v] == inf) continue;
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
        return dist[dest];
    }
};