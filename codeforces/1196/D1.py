def gen(n, b):
	a = [(x + b) % 3 for x in range(n)]
	s = ""
	for i in range(n):
		if a[i] == 0:
			s += "R"
		if a[i] == 1:
			s += "G"
		if a[i] == 2:
			s += "B"
	return s

q = int(input())
for _ in range(q):
	n, k = map(int, input().split())
	s = input()
	ans = n
	for xi in range(3):
		t = gen(n, xi)
		diff = 0
		for i in range(k):
			if s[i] != t[i]:
				diff += 1
		ans = min(ans, diff)
		for j in range(k, n):
			if s[j - k] != t[j - k]:
				diff -= 1
			if s[j] != t[j]:
				diff += 1
			ans = min(ans, diff)
	print(ans)