inf = 10 ** 9
n = int(input())
a = [int(input()) for x in range(n)]
m1 = -inf
m2 = -inf
for i in range(n):
    if a[i] >= m1:
        m2 = m1
        m1 = a[i]
    elif a[i] > m2:
        m2 = a[i]
for i in range(n):
    if m1 != a[i]:
        print(m1)
    else:
        print(m2)