n, k, q = map(int, input().split())
a = [k - q] * n
for i in range(q):
    z = int(input())
    a[z - 1] += 1
for i in range(n):
    if a[i] > 0:
        print("Yes")
    else:
        print("No")