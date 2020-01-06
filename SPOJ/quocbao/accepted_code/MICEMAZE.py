import heapq
graph = [[] for i in range(510)]

def dijkstra(u):
    d[u] = 0
    minHeap = []
    heapq.heappush(minHeap, (u, 0))
    while len(minHeap) > 0:
        s = heapq.heappop(minHeap)
        u = s[0]
        if d[u] < s[1]:
            continue
        for i in graph[u]:
            v = i[0]
            w = i[1]
            if d[v] > d[u] + w:
                d[v] = d[u] + w
                heapq.heappush(minHeap, (v, d[v]))
    

n = int(input())
e = int(input())
timer = int(input())
m = int(input())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

INF = int (1e9)
res = 0
for i in range(1, n + 1):
    d = [INF] * (n + 1)
    dijkstra(i)
    if d[e] <= timer:
        res += 1
print(res)