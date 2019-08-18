n = int(input())
v = list(map(int, input().split()))
v.sort(reverse=True)
i = n - 1
while i > 0:
    x = (v[i] + v[i - 1])/2
    v.pop()
    v.pop()
    v.append(x)
    i -= 1
print(v[0])