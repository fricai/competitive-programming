q = int(input())

for _ in range(q):
	s = [""] * 3
	freq = [[0] * 26 for i in range(3)]
	for i in range(3):
		s[i] = input()
		for x in s[i]:
			freq[i][ord(x) - ord('a')] += 1

	def check(m, n):
		if (m == 0):
			return True
		if (n == 0):
			return False
		if s[0][m - 1] == s[1][n - 1]:
			return check(m - 1, n - 1)
		return check(m, n - 1)

	flag = True
	for i in range(26):
		if freq[0][i] + freq[2][i] < freq[1][i]:
			flag = False
	if flag and check(len(s[0]), len(s[1])):
		print("YES")
	else:
		print("NO")
