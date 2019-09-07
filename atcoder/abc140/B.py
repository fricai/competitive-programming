n = int(input())
a = [int(x) - 1 for x in input().split()]
b = list(map(int, input().split()))
c = list(map(int, input().split()))

ans = b[a[0]]
for i in range(1, n):
	ans += b[a[i]]
	if a[i - 1] + 1 == a[i]:
		ans += c[a[i - 1]]
print(ans)