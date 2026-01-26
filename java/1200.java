class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int minDelta = Integer.MAX_VALUE;
        int n = arr.length;
        for(int i = 1; i < n; i++){
            minDelta = Math.min(minDelta, arr[i] - arr[i - 1]);
        }
        List<List<Integer>> result = new ArrayList<>(); 
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i - 1] == minDelta)
                result.add(List.of(arr[i - 1], arr[i]));
        }
        return result;
    }
}