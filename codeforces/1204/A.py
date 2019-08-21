s = input()
n = len(s)
flag = False
for i in range(1, n):
    if s[i] != '0':
        flag = True

if flag:
    print((n + 1)// 2)
else:
    print(n // 2)