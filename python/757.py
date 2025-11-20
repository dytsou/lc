class Solution:
    def intersectionSizeTwo(self, intervals: list[list[int]]) -> int:
        # Sort by end time (ascending), then by start time (descending) when end times are equal
        intervals.sort(key=self._cmp_key)
        
        count = 2  # Start with 2 numbers from the first interval
        last = intervals[0][1]        # Last number selected
        second_last = last - 1        # Second-to-last number selected
        
        for interval in intervals:
            start, end = interval[0], interval[1]
            
            # If second_last >= start, the interval already has at least 2 numbers covered
            if second_last >= start: 
              continue
            
            # Check if the interval doesn't overlap with current range [second_last, last]
            no_overlap = start > last
            
            # Add 1 or 2 numbers depending on overlap
            count += 1 + no_overlap
            
            # Update the last two numbers selected
            if no_overlap:
              second_last = end - 1
            else:
              second_last = last
            last = end
        
        return count
    
    @staticmethod
    def _cmp_key(interval: list[int]) -> tuple:
        """Sort key: by end time (ascending), then by start time (descending) when end times are equal"""
        return (interval[1], -interval[0])

