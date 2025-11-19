class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        for(;; original *= 2){
            auto it = find(nums.begin(), nums.end(), original);
            if(it == nums.end()) break;
        }
        return original;
    }
};