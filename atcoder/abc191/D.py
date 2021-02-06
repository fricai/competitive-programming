from math import *
from decimal import Decimal

a, b, r = map(Decimal, input().split())

left = ceil(a - r)
right = floor(a + r)

ans = 0
for x in range(left, right + 1):
    d = (r * r - (a - x) * (a - x)).sqrt()
    L = ceil(b - d)
    R = floor(b + d)
    ans += R - L + 1
print(ans)