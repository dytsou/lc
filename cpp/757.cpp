class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end time (ascending), then by start time (descending) when end times are equal
        sort(intervals.begin(), intervals.end(), cmp);
        
        int count = 2;  // Start with 2 numbers from the first interval
        int last = intervals[0][1];        // Last number selected
        int secondLast = last - 1;        // Second-to-last number selected
        
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            
            // If secondLast >= start, the interval already has at least 2 numbers covered
            if (secondLast >= start) continue;
            
            // Check if the interval doesn't overlap with current range [secondLast, last]
            bool noOverlap = start > last;
            
            // Add 1 or 2 numbers depending on overlap
            count += 1 + noOverlap;
            
            // Update the last two numbers selected
            secondLast = noOverlap ? end - 1 : last; // if no overlap, update secondLast to end - 1
            last = end; // update last to end
        }
        
        return count;
    }
private:
    static bool cmp(const vector<int>& interval1, const vector<int>& interval2) {
        int start1 = interval1[0], end1 = interval1[1];
        int start2 = interval2[0], end2 = interval2[1];
        return (end1 == end2) ? start1 > start2 : end1 < end2;
    }
};