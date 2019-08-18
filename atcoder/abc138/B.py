n = int(input())
a = list(map(int, input().split()))
s = 0    
for x in a:
    s += 1/x
print(1/s)