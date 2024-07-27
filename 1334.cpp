#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        makeGraph(n, edges);
        flyodWarshall(n);
        int node = -1, minCount = INT_MAX;
        for(int i=0; i<n; i++){
            int currCount = count(i, n, distanceThreshold);
            if(currCount <= minCount){
                minCount = currCount;
                node = i;
            }
        }
        return node;
    }
private:
    vector<vector<int>> graph;
    void makeGraph(int n, vector<vector<int>>& edges){
        graph = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for(auto edge : edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
    }
    void flyodWarshall(int n){
        for(int i=0; i<n; i++) graph[i][i] = 0;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i == j) continue;
                    if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX){
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
    }
    int count(int currNode, int n, int distanceThreshold){
        int count = 0;
        for(int j=0; j<n; j++){
            count += (graph[currNode][j] <= distanceThreshold && currNode != j);
        }
        return count;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int distanceThreshold;
    cin >> distanceThreshold;
    Solution s;
    cout << s.findTheCity(n, edges, distanceThreshold) << endl;
}