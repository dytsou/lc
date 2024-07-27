#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        long long totalCost = 0;
        init(source, target, original, changed, cost);
        makeGraph();
        floydWarshall(26);
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(minCost[u][v] >= INT_MAX) return -1;
            totalCost += minCost[u][v];
        }
        return totalCost;
    }
private:
    string source;
    string target;
    vector<char>& original;
    vector<char>& changed;
    vector<int>& cost;
    vector<vector<long long>> minCost;
    void init(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        this->source = source;
        this->target = target;
        this->original = original;
        this->changed = changed;
        this->cost = cost;
        this->minCost.resize(26, vector<long long>(26, INT_MAX));
    }
    void makeGraph(){
        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            minCost[u][v] = min(minCost[u][v], (long long)cost[i]);
        }
    }
    void floydWarshall(int n){
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j < n; j++) {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
    }
};

signed main(){
    string source, target;
    cin >> source >> target;
    long long n;
    cin >> n;
    vector<char> original(n), changed(n);
    vector<int> cost(n);
    for(long long i = 0; i < n; i++){
        char a, b;
        long long c;
        cin >> a >> b >> c;
        original[i] = a;
        changed[i] = b;
        cost[i] = c;
    }
    Solution s;
    cout << s.minimumCost(source, target, original, changed, cost) << endl;
}