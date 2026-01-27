class Solution {
    public int minCost(int n, int[][] edges) {
        List<List<int []>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for(int [] e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            graph.get(u).add(new int[]{v, w});
            graph.get(v).add(new int[]{u, 2 * w});            
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.add(new int[]{0, 0});
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int node = curr[0];
            int d = curr[1];
            if(dist[node] < d) continue;
            for(int[] neighbor : graph.get(node)){
                int neighborNode = neighbor[0];
                int weight = neighbor[1];
                if(d + weight < dist[neighborNode]){
                    dist[neighborNode] = d + weight;
                    pq.add(new int[]{neighborNode, dist[neighborNode]});
                }
            }
        }
        return dist[n - 1] == Integer.MAX_VALUE ? -1 : dist[n - 1];
    }
}