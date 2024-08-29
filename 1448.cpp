#include<iostream>
#include<vector>
#include<climits>
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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* root, int maxVal) {
        if (root == nullptr) return 0;
        int res = (root->val >= maxVal) ? 1 : 0;
        int nextMaxVal = max(maxVal, root->val);
        return res + dfs(root->left, nextMaxVal) + dfs(root->right, nextMaxVal);
    }
};