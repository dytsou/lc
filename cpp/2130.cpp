#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int maxSum = 0;
        for(int i = 0, j = v.size() - 1; i < j; i++, j--)
            maxSum = max(maxSum, v[i] + v[j]);
        return maxSum;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        head->next = new ListNode(x);
        head = head->next
    }
    cout << s.pairSum(head) << endl;
    return 0;
}
