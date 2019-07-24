q = int(input())
inf = 10 ** 5

for _ in range(q):
	n = int(input())
	l = -inf
	r = +inf
	u = +inf
	d = -inf
	for xi in range(n):
		x, y, f1, f2, f3, f4 = map(int, input().split())
		if not f1:
			l = max(x, l)
		if not f2:
			u = min(y, u)
		if not f3:
			r = min(x, r)
		if not f4:
			d = max(y, d)
	if l > r or d > u:
		print(0)
	else:
		print(1, (l + r)//2, (u + d)//2)