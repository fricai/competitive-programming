n, l, r = map(int, input().split())
mx = 0
for x in range(l, min(n + 1, r + 1)):
    mx = max((n - x + 2) * (1 << (x - 1)) - 1, mx)
mi = (n - l) + (1 << l) - 1
print(mi, mx)