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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;
        while (curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != nullptr) next = next->next;
        }
        return prev;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    head = head->next;
    ListNode *res = s.reverseList(head);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}