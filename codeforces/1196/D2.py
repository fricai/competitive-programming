import sys
input = sys.stdin.readline

q = int(input())
for _ in range(q):
	n, k = map(int, input().split())
	s = input()

	a = [0] * n
	for i in range(n):
		if s[i] == "R":
			a[i] = 0
		if s[i] == "G":
			a[i] = 1
		if s[i] == "B":
			a[i] = 2

	ans = n
	for b in range(3):
		diff = 0

		for i in range(k):
			if a[i] != (i + b) % 3:
				diff += 1
		ans = min(ans, diff)

		for j in range(k, n):
			if a[j - k] != (j - k + b) % 3:
				diff -= 1
			if a[j] != (j + b) % 3:
				diff += 1
			ans = min(ans, diff)

	print(ans)