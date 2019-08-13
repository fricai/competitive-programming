q = int(input())

for _ in range(q):
	n = int(input())
	p = list(map(int, input().split()))

	st = 0
	for i in range(n):
		if p[i] == 1:
			st = i
			break
	
	i = 0
	flag1 = True
	for i in range(n):
		if p[(st + i) % n] != i + 1:
			flag1 = False

	p.reverse()
	st = n - st - 1
	flag2 = True

	for i in range(n):
		if p[(st + i) % n] != i + 1:
			flag2 = False

	if flag1 or flag2:
		print("YES")
	else:
		print("NO")
