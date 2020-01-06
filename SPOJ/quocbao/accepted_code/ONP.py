
def transform(a):
    s = []
    for symbol in a: 
        if symbol.isalpha():
            print(symbol, end='')
            continue
        if symbol == ')':
            print(s.pop(), end='')
            continue
        if symbol != '(':
            s.append(symbol)
    print()


t = int(input())
while t > 0:
    t -= 1
    expression = input()
    transform(expression)


