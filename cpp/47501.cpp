class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        // Store positions of each number
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int minDist = INT_MAX;
        
        // For each number that appears at least 3 times
        for (auto& p : positions) {
            vector<int>& indices = p.second;
            if (indices.size() < 3) continue;
            
            // Check all consecutive pairs of indices
            // For sorted indices i < j < k, distance = 2(k-i)
            for (int j = 1; j < indices.size() - 1; j++) {
                int i = indices[j-1];
                int k = indices[j+1];
                int dist = 2 * (k - i);
                minDist = min(minDist, dist);
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};