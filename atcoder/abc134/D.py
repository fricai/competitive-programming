n = int(input())
a = [0]
for x in input().split():
	a.append(int(x))
x = [0] * (n + 1)

i = n
while i > 0:
	x[i] = a[i]
	j = 2 * i
	while j <= n:
		x[i] += x[j]
		x[i] %= 2
		j += i
	i -= 1

m = 0
for i in range(1, n + 1):
	if x[i] == 1:
		m += 1
print(m)
for i in range(1, n + 1):
	if x[i] == 1:
		print(i, end=" ")