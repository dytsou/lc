import java.util.*;

class Solution {
    int n;
    boolean[] removed;
    int[] next;
    int[] prev;
    long[] cval;
    PriorityQueue<Pair> pq;
    int inversions;
    
    static class Pair {
        long sum;
        int pos;
        Pair(long sum, int pos) {
            this.sum = sum;
            this.pos = pos;
        }
    }
    
    void init(int[] v) {
        n = v.length;
        removed = new boolean[n];
        prev = new int[n];
        next = new int[n];
        cval = new long[n];
        inversions = 0;
        for(int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
            cval[i] = v[i];
        }
        pq = new PriorityQueue<>((a, b) -> {
            int cmp = Long.compare(a.sum, b.sum);
            if(cmp != 0) return cmp;
            return Integer.compare(a.pos, b.pos);
        });
        for(int i = 0; i < n - 1; i++) {
            if(cval[i] > cval[i + 1]) {
                inversions++;
            }
            pq.offer(new Pair(cval[i] + cval[i + 1], i));
        }
    }
    
    boolean isSorted() {
        return inversions == 0;
    }
    
    int topElement() {
        while(!pq.isEmpty()) {
            int pos = pq.peek().pos;
            long asum = pq.peek().sum;
            if(removed[pos] || next[pos] == n ||
                cval[pos] + cval[next[pos]] != asum) {
                pq.poll();
            } else {
                break;
            }
        }
        if(pq.isEmpty()) return -1;
        return pq.peek().pos;
    }
    
    void merge(int i) {
        int j = next[i];
        if(j == n) return;
        int x = prev[i];
        int y = next[j];
        if(cval[i] > cval[j]) inversions--;
        if(x != -1 && cval[x] > cval[i]) inversions--;
        if(y != n && cval[j] > cval[y]) inversions--;
        if(x != -1 && cval[x] > cval[i] + cval[j]) inversions++;
        if(y != n && cval[i] + cval[j] > cval[y]) inversions++;
        cval[i] += cval[j];
        removed[j] = true;
        next[i] = y;
        if(y != n) {
            prev[y] = i;
            pq.offer(new Pair(cval[i] + cval[y], i));
        }
        if(x != -1) {
            pq.offer(new Pair(cval[x] + cval[i], x));
        }
    }
    
    public int minimumPairRemoval(int[] nums) {
        init(nums);
        int ans = 0;
        while(!isSorted()) {
            int pos = topElement();
            merge(pos);
            ans++;
        }
        return ans;
    }
}
