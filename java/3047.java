class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;
        long result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left   = Math.max(bottomLeft[i][0], bottomLeft[j][0]);
                int right  = Math.min(topRight[i][0],  topRight[j][0]);
                if (right <= left) continue;

                int bottom = Math.max(bottomLeft[i][1], bottomLeft[j][1]);
                int top    = Math.min(topRight[i][1],  topRight[j][1]);
                if (top <= bottom) continue;

                int side = Math.min(right - left, top - bottom);
                result = Math.max(result, (long) side * side);
            }
        }
        return result;
    }
}