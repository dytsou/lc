#include<iostream>

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *ptr = head;
        ListNode *oddHead = new ListNode(0);
        ListNode *evenHead = new ListNode(0);
        ListNode *oddPtr = oddHead, *evenPtr = evenHead;
        bool isOdd = true;
        while(ptr != nullptr){
            if(isOdd){
                oddPtr->next = ptr;
                oddPtr = oddPtr->next;
            }
            else{
                evenPtr->next = ptr;
                evenPtr = evenPtr->next;
            }
            isOdd = !isOdd;
            ptr = ptr->next;
        }
        evenPtr->next = nullptr;
        oddPtr->next = evenHead->next;
        return oddHead->next;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    ListNode *head = new ListNode(0);
    ListNode *ptr = head;
    while(n--){
        int x;
        cin >> x;
        ptr->next = new ListNode(x);
        ptr = ptr->next;
    }
    ListNode *ans = s.oddEvenList(head->next);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}