class Scanner:
    import sys
    def __init__(self, istream = sys.stdin):
        self.tokenizer = Scanner.__tokenizer__(istream)
    def __tokenizer__(istream):
        for line in istream:
            for token in line.strip().split():
                yield token
        while True:
            yield None
    def next(self, type = str, rep = 1):
        if rep == 1:
            return type(self.tokenizer.__next__())
        return [type(self.tokenizer.__next__()) for i in range(rep)]

graph = [[] for _ in range(10005)]

def DFS(scr):
    visited = [False] * (N + 1)
    s = [scr]
    visited[scr] = True
    nbombs = 0

    while len(s):
        u = s.pop()
        nbombs += 1

        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                s.append(v)

    return nbombs

sc = Scanner()
N, M = sc.next(int, 2)

for _ in range(M):
    u, v = sc.next(int, 2)
    graph[u].append(v)

max_bombs = 0

for i in range(1, N + 1):
    max_bombs = max(max_bombs, DFS(i))

print(max_bombs)