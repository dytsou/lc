from typing import List

class Solution:
  def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
    components = 0
    graph = [[] for _ in range(n)]
    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)
    def dfs(node: int, parent: int) -> int:
      nonlocal components, graph, values, k
      subtree_sum = values[node]
      for neighbor in graph[node]:
        if neighbor == parent: continue
        child_sum = dfs(neighbor, node)
        subtree_sum = (subtree_sum + child_sum) % k
      if subtree_sum % k == 0:
        components += 1
        return 0
      return subtree_sum % k

    dfs(0, -1)
    return components