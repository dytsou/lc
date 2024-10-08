#include<iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            carry = sum/10;
            sum = sum%10;
            ptr->val = sum;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            if(l1 || l2){
                ptr->next = new ListNode();
                ptr = ptr->next;
            }
        }
        if(carry){
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = carry;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n1, n2;
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;
    cin >> n1 >> n2;
    for(int i=0; i<n1; i++){
        int x;
        cin >> x;
        ptr1->val = x;
        if(i != n1-1){
            ptr1->next = new ListNode();
            ptr1 = ptr1->next;
        }
    }
    for(int i=0; i<n2; i++){
        int x;
        cin >> x;
        ptr2->val = x;
        if(i != n2-1){
            ptr2->next = new ListNode();
            ptr2 = ptr2->next;
        }
    }
    ListNode* ans = s.addTwoNumbers(l1, l2);
    while(ans){
        cout << ans->val;
        ans = ans->next;
        if(ans) cout << ",";
    }
    cout << endl;
    return 0;
}