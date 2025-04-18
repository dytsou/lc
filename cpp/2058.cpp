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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPointsLocation;
        vector<int> ans;
        int left = head->val;
        int location = 1;
        while(head->next){
            if((left < head->val && head->val > head->next->val) || (left > head->val && head->val < head->next->val))
                criticalPointsLocation.push_back(location);
            left = head->val;
            head = head->next;
            location++;
        }
        if(criticalPointsLocation.size() < 2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int minDistance = criticalPointsLocation[1] - criticalPointsLocation[0];
        int maxDistance = criticalPointsLocation.back() - criticalPointsLocation[0];
        for(int i=1; i<criticalPointsLocation.size()-1; i++){
            int distance = criticalPointsLocation[i+1] - criticalPointsLocation[i];
            minDistance = minDistance < distance ? minDistance : distance;
        }
        ans.push_back(minDistance);
        ans.push_back(maxDistance);
        return ans;
    }
};

int main(){
    Solution s;
    int n;
    ListNode* l = new ListNode();
    ListNode* ptr = l;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        ptr->val = x;
        if(i != n-1){
            ptr->next = new ListNode();
            ptr = ptr->next;
        }
    }
    vector<int> ans = s.nodesBetweenCriticalPoints(l);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}