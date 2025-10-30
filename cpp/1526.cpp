class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = (int)target.size();
        int result = 0;
        result += target[0];
        for (int i = 1; i < n; i++) {
            if (target[i] > target[i - 1]) {
                result += target[i] - target[i - 1];
            }
        }
        return result;
    }
};