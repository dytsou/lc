class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> yCounts;
        yCounts.reserve(points.size());
        for(auto &point : points)
            yCounts[point[1]]++;
        
        long long sum = 0;
        long long sumSquares = 0;
        
        for(auto &[y, count] : yCounts) {
            if(count <= 1) continue;
            const long long pairs = (long long)count * (count - 1) / 2;
            sum += pairs;
            sumSquares += pairs * pairs;
        }
        
        // Use formula: Σ_{i<j} a_i * a_j = ((Σ a_i)² - Σ a_i²) / 2
        long long result = sum * sum - sumSquares;
        result /= 2;
        result %= MOD;
        
        return (int)result;
    }
private:
    static const int MOD = 1e9 + 7;
};