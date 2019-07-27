a, b = map(int, input().split())
if a % 2 == b % 2:
	print((a + b)//2)
else:
	print("IMPOSSIBLE")