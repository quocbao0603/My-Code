
while True:
    n = int(input())
    if n == 0 : break
    a = list(map(int,input().split()))
    parking_truck = []
    ordering = 1
    i = 0
    amax = 0
    flag = True
    while (i < n):
        if a[i] != ordering: 
            parking_truck.append(a[i])
        else: 
            ordering += 1
        i += 1
        while (True):
            if len(parking_truck) > 0 and parking_truck[-1] == ordering: 
                parking_truck.pop()
                ordering += 1
                continue
            break
        #print(parking_truck, ordering)
    if len(parking_truck) > 0:  print('no')
    else: print('yes')
    while len(parking_truck) > 0: parking_truck.pop()
        
