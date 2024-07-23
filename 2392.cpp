#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions){
        vector<vector<int>> result(k, vector<int>(k));
        init(k);
        for(vector<int> &condition : rowConditions) addCondition(condition[0], condition[1]);
        topoSort(rows);
        refresh();
        for(vector <int> &condition : colConditions) addCondition(condition[0], condition[1]);
        topoSort(columns);
        for(int i = 1; i <= k; ++i) {
            if(rows[i] == -1 || columns[i] == -1) return {};
            result[rows[i]][columns[i]] = i;
        }
        return result;
    }
private:
    int k;
    vector<int> rows, columns;
    vector<vector<int>> adjacencyList;
    vector<vector<bool>> appeared;
    vector<int> indegrees;
    void init(int k){
        this->k = k;
        rows = vector<int>(k+1, -1);
        columns = vector<int>(k+1, -1);
        adjacencyList = vector<vector<int>>(k+1);
        appeared = vector<vector<bool>>(k+1, vector<bool>(k+1, false));
        indegrees = vector<int>(k+1, 0);
    };
    void addCondition(int from, int to){
        if(appeared[from][to]) return;
        appeared[from][to] = true;
        adjacencyList[from].push_back(to);
        indegrees[to]++;
    };
    void topoSort(vector<int> &row){
        int nowRow = 0;
        queue<int> q;
        for(int i = 1; i <= k; ++i){
            if(!indegrees[i]) q.push(i);
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i : adjacencyList[now]){
                --indegrees[i];
                if(!indegrees[i]) q.push(i);
            }
            row[now] = nowRow++;
        }
    };
    
    void refresh(){
        for(int i = 1; i <= k; ++i){
            appeared[i] = vector<bool>(k+1, false);
            adjacencyList[i].clear();
            indegrees[i] = 0;
        }
    };
};

int main(){
    int k;
    cin >> k;
    vector<vector<int>> rowConditions, colConditions;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        rowConditions.push_back(vector<int>({x, y}));
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        colConditions.push_back(vector<int>({x, y}));
    }
    Solution solution;
    vector<vector<int>> result = solution.buildMatrix(k, rowConditions, colConditions);
    for(vector<int> &row : result){
        for(int i : row) cout << i << " ";
        cout << endl;
    }
    return 0;
}