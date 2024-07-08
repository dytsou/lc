#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size()) / 2;
        int i = 0, j = 0;
        vector<int> nums;
        while(nums.size() <= mid) {
            if (i < nums1.size() && j < nums2.size())
                nums.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
            else if (i < nums1.size()) 
                nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        return (nums1.size() + nums2.size()) % 2 == 0 ? (nums[mid-1] + nums[mid]) / 2.0 : nums[mid];
    }
};

int main() {
    Solution s;
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}