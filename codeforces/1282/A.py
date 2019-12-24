t = int(input())

for _ in range(t):
    a, b, c, r = map(int, input().split())
    if (a > b):
        a, b = b, a
    if c + r < a or c - r > b:
        print(b - a)
    else:
        print(max(0, (c - r) - a) + max(0, b - (c + r)))