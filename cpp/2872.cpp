class Solution {
public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    // Build adjacency list
    this->nodes = n;
    this->divisors = k;
    this->values = values;
    graph.resize(n);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // Start DFS from root (node 0)
    dfs(0, -1);
    return components;
  }
private:
  vector<vector<int>> graph;
  vector<int> values;
  int components = 0;
  int nodes;
  int divisors;

  // DFS function: returns the sum of subtree modulo divisors
  // When we find a subtree divisible by divisors, we cut it (return 0 to parent)
  long long dfs(int node, int parent){
    long long subtreeSum = values[node];
      
    // Process all children
    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        long long childSum = dfs(neighbor, node);
        subtreeSum = (subtreeSum + childSum) % divisors;
    }
    
    // If subtree sum is divisible by k, we can cut the edge to parent
    // This creates a new component (count it)
    if (subtreeSum % divisors == 0) {
        components++;
        // After cutting, return 0 so parent doesn't include this subtree
        return 0;
    }
    
    // Otherwise, return the remainder for parent to accumulate
    return subtreeSum % divisors;
  }
};