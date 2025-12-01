class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // Sort batteries to get the n largest ones
        sort(batteries.begin(), batteries.end());
        
        // Get the sum of all extra batteries (smallest ones)
        long long extra = 0;
        for (int i = 0; i < batteries.size() - n; i++) {
            extra += batteries[i];
        }
        
        // live stands for the n largest batteries we chose for n computers
        // We'll work with the last n elements
        int startIdx = batteries.size() - n;
        
        // We increase the total running time using 'extra' by increasing
        // the running time of the computer with the smallest battery.
        for (int i = 0; i < n - 1; i++) {
            // If the target running time is between live[i] and live[i + 1]
            long long gap = batteries[startIdx + i + 1] - batteries[startIdx + i];
            if (extra / (i + 1) < gap) {
                return batteries[startIdx + i] + extra / (i + 1);
            }
            
            // Reduce 'extra' by the total power used.
            extra -= (i + 1) * gap;
        }
        
        // If there is power left, we can increase the running time
        // of all computers.
        return batteries.back() + extra / n;
    }
};