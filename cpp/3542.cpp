class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int result = 0;
        for (int a : nums) {
            while (!s.empty() && s.back() > a) {
                s.pop_back();
            }
            if (a == 0) continue;
            if (s.empty() || s.back() < a) {
                result++;
                s.push_back(a);
            }
        }
        return result;
    }
};