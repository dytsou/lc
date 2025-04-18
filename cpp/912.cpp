#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> merged;
        int a = left, b = mid+1;
        while(a <= mid && b <= right){
            if(nums[a] <= nums[b]) merged.push_back(nums[a++]);
            else merged.push_back(nums[b++]);
        }
        while(a <= mid) merged.push_back(nums[a++]);
        while(b <= right) merged.push_back(nums[b++]);
        for(int i = 0; i < merged.size(); ++i) 
            nums[left + i] = merged[i];
        return;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
        return;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<int> ans = s.sortArray(nums);
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}