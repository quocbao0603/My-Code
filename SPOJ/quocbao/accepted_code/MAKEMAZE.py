import queue 
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
MAXN = 21

class Cell:
    def __init__(self, _r, _c):
        self.r = _r
        self.c = _c

def isValid(i, j):
    if 0 <= i < m and 0 <= j < n:
        return True
    return False

def bfs(i, j):
    q = queue.Queue()
    visited[i][j] = 1
    q.put(Cell(i, j))
    
    while not q.empty():
        u = q.get()
       # print(u.r, u.c)
        for k in range(4):
            ux = u.r + dx[k]
            uy = u.c + dy[k]
            
            if isValid(ux, uy) and visited[ux][uy] == 0 and maze[ux][uy] == '.':
                q.put(Cell(ux, uy))
                visited[ux][uy] = visited[u.r][u.c] + 1


testcase = int(input())
for _ in range(testcase):
    visited = [[0] * MAXN for _ in range(MAXN)]
    m, n = map(int, input().split())
    maze = [input() for i in range(m)]
    #print(*a, sep = '\n')
    count = 0
    for i in range(m):
        for j in range(n):
            if i == 0 or  i == m - 1 or j == 0 or j == n - 1:
                if maze[i][j] == '.': count += 1
    if count != 2:
        print("invalid")
        continue

    count = 0
    for i in range(m):
        for j in range(n):
            if i == 0 or  i == m - 1 or j == 0 or j == n - 1:
                if maze[i][j] == '.' and visited[i][j] == 0: 
                   # print(i, j)
                    bfs(i, j)
                    count += 1
                    
    if count == 1: 
        print("valid")
    else:
        print("invalid")
                    
                    
    
    
    