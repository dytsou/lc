class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0;
        int n = nums.size();
        vector<bool> result(n, false);
        for (int i = 0; i < n; i++) {
            curr = (curr * 2 + nums[i]) % 5;
            if (curr == 0) result[i] = true;
        }
        return result;
    }
};