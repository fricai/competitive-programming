q = int(input())
for _ in range(q):
	n, m = map(int, input().split())
	g = [[False] * m for i in range(n)]

	for i in range(n):
		s = input()
		for j in range(m):
			g[i][j] = (s[j] == '.')

	cntv = [0] * n
	cnth = [0] * m
	for i in range(n):
		for j in range(m):
			cntv[i] += g[i][j]
			cnth[j] += g[i][j]
	ans = 10 ** 9
	for i in range(n):
		for j in range(m):
			x = cntv[i] + cnth[j]
			if g[i][j]:
				x -= 1
			ans = min(ans, x)
	print(ans)
