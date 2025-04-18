#include<iostream>
#include<vector>
#include<queue>

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
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
private:
    vector<int> dfs(TreeNode* root, int distance, int& ans){
        if(root == nullptr) return {};
        if(root->left == nullptr && root->right == nullptr) return {1};
        vector<int> left = dfs(root->left, distance, ans);
        vector<int> right = dfs(root->right, distance, ans);
        for(int l : left){
            for(int r : right){
                if(l + r <= distance) ans++;
            }
        }
        vector<int> returnDistance;
        for(int l : left){
            if(l + 1 < distance) returnDistance.push_back(l + 1);
        }
        for(int r : right){
            if(r + 1 < distance) returnDistance.push_back(r + 1);
        }
        return returnDistance;
    }
};

TreeNode* makeTree(vector<int>& tree){
    TreeNode* root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (i < tree.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (tree[i] != -1) {
            node->left = new TreeNode(tree[i]);
            q.push(node->left);
        }
        i++;
        if (i < tree.size() && tree[i] != -1) {
            node->right = new TreeNode(tree[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> tree(n);
    for(int i=0; i<n; i++)
        cin >> tree[i];
    TreeNode* root = makeTree(tree);
    int distance;
    cin >> distance;
    cout << s.countPairs(root, distance) << endl;
    return 0;
}
