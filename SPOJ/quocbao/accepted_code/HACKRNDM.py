import sys
class Scanner:
    def __init__(self, istream):
        self.tokenizer = Scanner.__tokenizer__(istream)
    def __tokenizer__(istream):
        for line in istream:
                for token in line.strip().split():
                        yield token
    def next(self):
        return self.tokenizer.__next__()

def BS_search(a, l, r, value):
    while l <= r:
        mid = int( (l + r) / 2 )
        if a[mid] == value:
            return True
        if a[mid] > value:
            r = mid - 1
        else:
            l = mid + 1
    return False

def solve():
    sc = Scanner(sys.stdin)
    n = int(sc.next())
    k = int(sc.next())
    a = []
    for i in range(n):
        x = int(sc.next())
        a.append(x)
    a.sort()
    ans = 0
    j = 0
    for i in range(n):
        while j < i and  a[i] - a[j] > k:
            j += 1
        if a[i] - a[j] == k:
            ans += 1
    print(ans)

solve()
