t = int(input())
for _ in range(t):
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())
    if h > c:
        h, c = c, h
        p, f = f, p
        
    ans = 0
    while b > 1:
        if f > 0:
            f -= 1
            ans += c
        elif p > 0:
            p -= 1
            ans += h
        b -= 2
    print(ans)