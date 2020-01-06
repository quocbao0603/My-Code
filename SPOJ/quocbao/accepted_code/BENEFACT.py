import sys
sys.setrecursionlimit(51000)
testcase = int(input())

MAX = 50010
dist = [0] * MAX
class Edge:
    def __init__(self, _v = 0, _w = 1):
        self.v = _v
        self.w = _w
    def __str__(self):
        s = "{0} {1}".format(self.v, self.w)
        return s

def dfs(u):
    for i in adj[u]:
        if dist[i.v] == 0:
            dist[i.v] = dist[u] + i.w 
            #print(u, i.v)
            dfs(i.v)

for _ in range(testcase):
    n = int(input())
    adj = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u, v, w = map(int, input().split())
        adj[u].append(Edge(v, w))
        adj[v].append(Edge(u, w))
        #print(u, v, w)
    #for i in range(1, n + 1):
    #    print(*adj[i], sep =', ')
    for i in range(1, n + 1):
        dist[i] = 0
    dist[1] = 1 
    dfs(1)
    #for i in range(1, n + 1):
    #    print(dist[i], end =' ')
    #print()
    index = 1
    for i in range(1, n + 1):
        if dist[i] > dist[index]: index = i
    for i in range(1, n + 1):
        dist[i] = 0
    dist[index] = 1
    dfs(index)
    index = 1
    for i in range(1, n + 1):
        if dist[i] > dist[index]: index = i
    print(dist[index] - 1)

    
