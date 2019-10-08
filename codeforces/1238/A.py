t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    if x - y != 1 and x - y != - 1:
        print("YES")
    else:
        print("NO")
