n = int(input())
b = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

s = 0
for i in range(n):
	if a[i] <= b[i]:
		s += a[i]
		b[i] -= a[i]
	else:
		s += b[i]
		a[i] -= b[i]
		b[i] = 0
		if a[i] <= b[i + 1]:
			s += a[i]
			b[i + 1] -= a[i]
		else:
			s += b[i + 1]
			b[i + 1] = 0
print(s)
