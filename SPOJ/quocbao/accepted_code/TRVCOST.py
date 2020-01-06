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
    

m = int(input())
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))
u = int(input())
INF = int(1e9)
d = [INF] * 510
dijkstra(u)
q = int(input())
for _ in range(q):
    v = int(input())
    if (d[v] == INF):
        print("NO PATH")
    else:
        print(d[v])
