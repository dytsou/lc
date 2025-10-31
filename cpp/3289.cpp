class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int mapping[101];
        for(int i : nums) mapping[i]++;
        vector<int> result;
        for(int i = 0; i < sizeof(mapping); i++){
            if(mapping[i] == 2) result.push_back(i);
            if(result.size() >= 2) return result;
        }
        return result;
    }
};
