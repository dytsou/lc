class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] result = new int[n];
        for(int i = 0; i < n; i++){
            int x = nums.get(i);
            if((x & 1) == 1)
                result[i] = x & ~(((x + 1) & ~x) >> 1);
            else
                result[i] = -1;
        }
        return result;
    }
}