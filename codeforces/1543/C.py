from decimal import Decimal
from functools import lru_cache

eps = Decimal(1e-6)
prec = 6

@lru_cache
def g(c, p, v):
    if abs(p - 1) <= eps:
        return Decimal(1)
    res = Decimal(1)
    if c <= v:
        res += c
    else:
        res += c * g(c - v, p + v, v)
    return res

@lru_cache
def f(c, m, p, v):
    if abs(p - 1) <= eps:
        return Decimal(1)
    res = Decimal(1)
    
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