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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
private:
    int dfs(TreeNode* root, long long targetSum){
        if (!root) return 0;
        int res = 0;
        if (root->val == targetSum) res++;
        res += dfs(root->left, targetSum - root->val);
        res += dfs(root->right, targetSum - root->val);
        return res;
    }
};