#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int group = n;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){ 
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    merge(parent, rank, group, i, j);
                }
            }
        }
        return n - group;
    }

private:
    int findParent(vector<int> &parent, int idx) {
        if (parent[idx] != idx)
            parent[idx] = findParent(parent, parent[idx]);
        return parent[idx];
    }
    void merge(vector<int> &parent, vector<int> &rank, int &group, int idx1, int idx2) {
        int root1 = findParent(parent, idx1);
        int root2 = findParent(parent, idx2);
        if (root1 != root2){
            if (rank[root1] > rank[root2])
                parent[root2] = root1;
            else if (rank[root1] < rank[root2])
                parent[root1] = root2;
            else{
                parent[root2] = root1;
                rank[root1]++;
            }
            group--;
        }
    }
};


int main(){
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> stones(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        cin >> stones[i][0] >> stones[i][1];
    cout << s.removeStones(stones) << endl;
    return 0;
}