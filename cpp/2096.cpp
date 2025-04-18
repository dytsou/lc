#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        dfs(root, startValue, startPath);
        dfs(root, destValue, destPath);
        string ans = "";
        while (!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()) {
            startPath.pop_back();
            destPath.pop_back();
        }
        reverse(destPath.begin(), destPath.end());
        return string(startPath.size(), 'U') + destPath;
    }
private:
    bool dfs(TreeNode* root, int startValue, string& startPath){
        if(root == nullptr) return false;
        if(root->val == startValue) return true;
        if(dfs(root->left, startValue, startPath)){
            startPath += "L";
            return true;
        }
        if(dfs(root->right, startValue, startPath)){
            startPath += "R";
            return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> tree(n);
    for(int i=0; i<n; i++)
        cin >> tree[i];
    TreeNode* root;
    queue<TreeNode*> q;
    q.push(root);
    for(int i=0; i<tree.size(); i++){
        if(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(tree[i] == -1) node->left = new TreeNode();
            else node->left = new TreeNode(tree[i]);
            i++;
            if(i >= tree.size()) break;
            if(tree[i] == -1) node->right = new TreeNode();
            else node->right = new TreeNode(tree[i]);
        } 
    }
    int start, dest;
    cin >> start >> dest;
    cout << s.getDirections(root, start, dest) << endl; 
}