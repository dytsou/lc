class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int INF = 1e6;
        // Track two smallest numbers in each remainder group (O(1) space)
        int rem1_min[2] = {INF, INF};
        int rem2_min[2] = {INF, INF};
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
            int r = num % 3;
            if (r == 1) {
                if (num < rem1_min[0]) {
                    rem1_min[1] = rem1_min[0];
                    rem1_min[0] = num;
                } else if (num < rem1_min[1]) {
                    rem1_min[1] = num;
                }
            } else if (r == 2) {
                if (num < rem2_min[0]) {
                    rem2_min[1] = rem2_min[0];
                    rem2_min[0] = num;
                } else if (num < rem2_min[1]) {
                    rem2_min[1] = num;
                }
            }
        }
        
        if (sum % 3 == 0) return sum;
        
        int minRemove = INF;
        if (sum % 3 == 1) {
            // Remove one smallest from rem1, or two smallest from rem2
              if (rem1_min[0] != INF) minRemove = min(minRemove, rem1_min[0]);
            if (rem2_min[0] != INF) minRemove = min(minRemove, rem2_min[0] + rem2_min[1]);
        } else { // sum % 3 == 2
            // Remove one smallest from rem2, or two smallest from rem1
            if (rem2_min[0] != INF) minRemove = min(minRemove, rem2_min[0]);
            if (rem1_min[0] != INF) minRemove = min(minRemove, rem1_min[0] + rem1_min[1]);
        }
        
        // If we can't make sum divisible by 3, return 0
        return (minRemove == INF) ? 0 : sum - minRemove;
    }
};