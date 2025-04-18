#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n];
        for(auto& edge : edges){
            int u = edge[0]-1, v = edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> dist(n, vector<int>(2,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 0;
        while(!q.empty()){
            auto [currTime, node] = q.front();
            q.pop();
            for(int& adjNode : adj[node]){
                int waitingTime = 0;
                if((currTime / change) % 2 == 1) 
                    waitingTime = change - (currTime % change);
                int newTime = time + currTime + waitingTime;
                if(dist[adjNode][0] > newTime){
                    dist[adjNode][1] = dist[adjNode][0];
                    dist[adjNode][0] = newTime;
                    q.push({newTime, adjNode});
                }
                else if(dist[adjNode][1] > newTime && dist[adjNode][0] < newTime ){
                    dist[adjNode][1] = newTime;
                    q.push({newTime, adjNode});
                }
            }
        }
        return dist[n-1][1];
    }
};

int main(){
    int n;
    cin >> n;
    int edge_n;
    cin >> edge_n;
    vector<vector<int>> edges(edge_n, vector<int>(2));
    for(int i = 0; i < edge_n; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    int time, change;
    cin >> time >> change;
    Solution s;
    cout << s.secondMinimum(n, edges, time, change) << endl;
    return 0;
}