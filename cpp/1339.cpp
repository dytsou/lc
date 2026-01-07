class Solution {
public:
    int maxProduct(TreeNode* root) {
        this->totalSum = 0;
        this->result = 0;
        totalSum = getSum(root);
        dfs(root);
        return int(result % MOD);
    }
private:
    int MOD = 1e9 + 7;
    long long totalSum;
    long long result;
    long long getSum(TreeNode* node){
        if (node == nullptr) return 0;
        return node->val + getSum(node->left) + getSum(node->right);
    }
    long long dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        long long left = dfs(node->left);
        long long right = dfs(node->right);
        long long subSum = node->val + left + right;
        long long currProduct = subSum * (totalSum - subSum);
        result = max(result, currProduct);
        return subSum;
    }
};