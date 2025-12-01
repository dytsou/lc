class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long maxTime = accumulate(batteries.begin(), batteries.end(), 0LL);
        return binarySearch(n, batteries, maxTime);
    }
private:
    bool canRunFor(int n, vector<int>& batteries, long long time) {
        long long total = 0;
        for (int b : batteries)
            total += min((long long)b, time);
        return total >= (long long)n * time;
    }
    long long binarySearch(int n, vector<int>& batteries, long long maxTime) {
        long long left = 0;
        long long right = maxTime;
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            
            if (canRunFor(n, batteries, mid))
                left = mid;  // mid is possible, try larger
            else
                right = mid - 1;  // mid is not possible, try smaller
        }
        return left;
    }
};