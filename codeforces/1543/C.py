from decimal import Decimal
from functools import lru_cache

one = Decimal(1)

@lru_cache
def g(c, p, v):
    if p == one:
        return one
    res = one
    if c <= v:
        res += c
    else:
        res += c * g(c - v, p + v, v)
    return res

@lru_cache
def f(c, m, p, v):
    if p == 1:
        return one
    res = one
    
    if m <= v:
        res += m * g(c + m / 2, p + m / 2, v)
    else:
        res += m * f(c + v / 2, m - v, p + v / 2, v)
    
    if c <= v:
        res += c * g(m + c / 2, p + c / 2, v)
    else:
        res += c * f(c - v, m + v / 2, p + v / 2, v)
    return res

def solve():
    c, m, p, v = map(Decimal, input().split())
    return f(c, m, p, v)

def main():
    t = int(input())
    for i in range(t):
        print(solve())
main()