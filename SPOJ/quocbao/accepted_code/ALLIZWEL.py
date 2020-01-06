import sys
sys.setrecursionlimit(100000)

dr = [0, 0, 1, 1, 1, -1, -1, -1]
dc = [1, -1, 0, 1, -1, 0, 1, -1]
term = "ALLIZZWELL"

def DFS(sr, sc, count):
    global found, table, visited
    if count == len(term):
        found = True
        return
    
    for i in range(8):
        r = sr + dr[i]
        c = sc + dc[i]

        if r in range(R) and c in range(C) and table[r][c] == term[count] and not visited[r][c]:
            visited[r][c] = True
            DFS(r, c, count + 1)
            visited[r][c] = False
    
T = int(input())

for _ in range(T):
    R, C = map(int, input().split())
    table = []
    visited = [[False] * C for _ in range(R)]

    for i in range(R):
        table.append(input())
    
    found = False

    for i in range(R):
        for j in range(C):
            if table[i][j] == term[0] and not found:
                DFS(i, j, 1)
    
    print("YES" if found else "NO")
    input()