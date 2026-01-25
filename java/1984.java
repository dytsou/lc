class Solution {
    public int minimumDifference(int[] nums, int k) {
        if (k == 1) return 0;
        Arrays.sort(nums);
        int delta = Integer.MAX_VALUE;
        for(int l = 0, r = k - 1; l <= nums.length - k; l++, r++)
            delta = Math.min(delta, nums[r] - nums[l]);
        return delta;
    }
}