a = []
mass = lambda c : 1 if c == 'H' else 12 if c == 'C' else 16

for c in input().strip():
    if c.isalpha():
        a.append(mass(c))
        continue
    if c.isnumeric():
        mol = a[-1] * int(c)
        a.pop()
        a.append(mol)
        continue
    if c == '(':
        a.append(-1)
        continue
    if c == ')':
        w = 0
        while a[-1] != -1:
            w += a[-1]
            a.pop()
        a.pop()
        a.append(w)

res = 0
for w in a: res += w
print(res)