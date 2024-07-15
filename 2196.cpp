#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for(vector<int>& description : descriptions){
            int target = description[0];
            int child = description[1];
            bool isLeft = description[2];
            TreeNode* node = this->findNode(target);
            if(isLeft){
                node->left = this->findNode(child);
                this->isRoot[child] = false;
            }
            else{
                node->right = this->findNode(child);
                this->isRoot[child] = false;
            }
        }
        return this->getRoot();
    }
private:
    unordered_map<int, TreeNode*> nodes;
    unordered_map<int, bool> isRoot;
    TreeNode* findNode(int target) {
        if (nodes.find(target) == nodes.end()) {
            this->nodes[target] = new TreeNode(target);
            this->isRoot[target] = true;
        }
        return this->nodes[target];
    }
    TreeNode* getRoot() {
        for(auto& [key, value] : this->isRoot) {
            if(value) return this->nodes[key];
        }
        return nullptr;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<vector<int>> descriptions(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> descriptions[i][0] >> descriptions[i][1] >> descriptions[i][2];
    TreeNode* root = solution.createBinaryTree(descriptions);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
    return 0;
}