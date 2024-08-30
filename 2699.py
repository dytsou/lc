class Solution:
    def modifiedGraphEdges(self, n: int, edges: list[list[int]], source: int, destination: int, target: int) -> list[list[int]]:
        inf = 2 * 10 ** 9
        def dijkstra():
            graph = [[inf] * n for _ in range(n)]
            dist = [inf] * n
            visited = [False] * n
            dist[source] = 0
            for u, v, w in edges:
                if w == -1:
                    continue
                graph[u][v] = w
                graph[v][u] = w
            for _ in range(n):
                u = -1
                for v in range(n):
                    if not visited[v] and (u == -1 or dist[v] < dist[u]):
                        u = v
                visited[u] = True
                for v in range(n):
                    if graph[u][v] != inf:
                        dist[v] = min(dist[v], dist[u] + graph[u][v])
            return dist[destination]
        
        path = dijkstra()
        if path < target:
            return []
        found = (path == target)
        for i in range(len(edges)):
            if edges[i][2] > 0:
                continue
            if found:
                edges[i][2] = inf
                continue
            edges[i][2] = 1
            path = dijkstra()
            if path <= target:
                found = True
                edges[i][2] = edges[i][2] + target - path
        return edges if found else []