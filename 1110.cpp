#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        vector<TreeNode*> ans;
        if(root == nullptr) return ans;
        unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        queue<TreeNode*> q;
        q.push(root);
        // .count = Number of elements with specified key. This function only makes sense for unordered_multisets; for unordered_set the result will either be 0 (not present) or 1 (present).
        if(!to_del.count(root->val)) ans.push_back(root); //root not be del
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(to_del.count(node->val)){ // this node would be del
                if(node->left && !to_del.count(node->left->val)) ans.push_back(node->left);
                if(node->right && !to_del.count(node->right->val)) ans.push_back(node->right);
            }
            if(node->left){
                q.push(node->left);
                if(to_del.count(node->left->val)) node->left = nullptr;
            }
            if(node->right){
                q.push(node->right);
                if(to_del.count(node->right->val)) node->right = nullptr;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> tree(n);
    for(int i=0; i<n; i++)
        cin >> tree[i];
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
        if (i >= tree.size()) break;
        if (tree[i] != -1) {
            node->right = new TreeNode(tree[i]);
            q.push(node->right);
        }
        i++;
    }
    int del_n;
    cin >> del_n;
    vector<int> to_delete(del_n);
    for(int i=0; i<del_n; i++)
        cin >> to_delete[i];
    vector<TreeNode*> ans = s.delNodes(root, to_delete);
    cout << "[";
    for(auto root : ans){
        if (root == nullptr) continue;
        cout << "[";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node != nullptr){
                cout << node->val << ", ";
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        cout << "\b\b]";
    }
    cout << "]\n";
    return 0;
}