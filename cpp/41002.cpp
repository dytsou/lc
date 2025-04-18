#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        buildGraph(edges);
        goodNodes = 0;
        dfs(0, -1);
        return goodNodes;
    }
private:
    vector<vector<int>> graph;
    int goodNodes;
    void buildGraph(vector<vector<int>>& edges){
        graph.resize(edges.size() + 1);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    int dfs(int u, int parent){
        int count = 1;
        vector<int> childrenSize;
        for(int v : graph[u]){
            if(v == parent) continue;
            int size = dfs(v, u);
            count += size;
            childrenSize.push_back(size);
        }
        if(childrenSize.size() == 0 || childrenSize.size() == 1){
            goodNodes++;
            return count;
        }
        int size0 = childrenSize[0];
        bool isGood = true;
        for(int i = 1; i < childrenSize.size(); i++){
            if(childrenSize[i] != size0){
                isGood = false;
                break;
            }
        }
        if(isGood) goodNodes++;
        return count;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        cin >> edges[i][0] >> edges[i][1];
    cout << s.countGoodNodes(edges) << endl;
    return 0;
}