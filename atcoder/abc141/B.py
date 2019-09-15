s = input()
flag = True
for i in range(len(s)):
    if (i % 2 == 0 and s[i] == 'L') or (i % 2 == 1 and s[i] == 'R'):
        flag = False
if flag:
    print("Yes")
else:
    print("No")