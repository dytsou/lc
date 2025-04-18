#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        init(n);
        vector<int> ans;
        for(auto & query : queries){
            add_road(query[0], query[1]);
            ans.push_back(dijkstra());
        }
        return ans;
    }
private:
    vector<vector<int>> g;
    void init(int n) {
        g = vector<vector<int>>(n);
        for(int i = 0; i < n - 1; i++){
            g[i].push_back(i+1);
        }
    }
    void add_road(int a, int b) {
        g[a].push_back(b);
    }
    int dijkstra() {
        int n = g.size();
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto v : g[u]){
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};