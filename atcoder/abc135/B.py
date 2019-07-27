n = int(input())
p = [int(x) for x in input().split()]

flag = all(p[i] <= p[i+1] for i in range(n - 1))

for i in range(n):
	for j in range(i + 1, n):
		p[i], p[j] = p[j], p[i]
		if all(p[i] <= p[i+1] for i in range(n - 1)):
			flag = True
			break
		p[i], p[j] = p[j], p[i]
	
if flag:
	print("YES")
else:
	print("NO")
