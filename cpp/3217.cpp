class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr = dummy;
        while (ptr->next) {
            if (s.count(ptr->next->val))
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        return dummy->next;
    }
};