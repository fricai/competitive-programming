n = int(input())
a = list(map(int, input().split()))
l = [1]
s = a[0]
t = a[0]
for i in range(1, n):
	t += a[i]
	if a[0] >= 2 * a[i]:
		s += a[i]
		l.append(i + 1)
if 2 * s > t:
	print(len(l))
	for j in l:
		print(j, end=" ")
else:
	print(0)
