class Solution {
    public int minimumPairRemoval(int[] nums) {
        int result = 0;
        int n = nums.length;
        while(!isSorted(nums, n)){
            result += 1;
            int pos = minPair(nums, n);
            nums[pos - 1] += nums[pos];
            for(int i = pos; i < n - 1; i++)
                nums[i] = nums[i + 1];
            n--;
        }
        return result;
    }
    private boolean isSorted(int[] nums, int n) {
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    private int minPair(int[] nums, int n){
        int minSum = Integer.MAX_VALUE;
        int pos = -1;
        for(int i = 1; i < n; i++){
            int sum = nums[i - 1] + nums[i];
            if(sum < minSum){
                minSum = sum;
                pos = i;
            }
        }
        return pos;
    }
}