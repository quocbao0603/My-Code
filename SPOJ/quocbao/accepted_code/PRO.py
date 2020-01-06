import heapq

taken = [False] * 1000005
maxHeap = []
minHeap = []
money = 0
nbills = 0

n = int(input())

for _ in range(n):
    a = list(map(int, input().split()))
    
    for x in a[1:]:
        nbills += 1
        heapq.heappush(maxHeap, (-x, nbills))
        heapq.heappush(minHeap, (x, nbills))

    while taken[maxHeap[0][1]]:
        heapq.heappop(maxHeap)
    
    while taken[minHeap[0][1]]:
        heapq.heappop(minHeap)
    
    taken[maxHeap[0][1]] = taken[minHeap[0][1]] = True
    money += -heapq.heappop(maxHeap)[0] - heapq.heappop(minHeap)[0]

print(money)