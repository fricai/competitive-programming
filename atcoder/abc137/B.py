k, x = map(int, input().split())
i = max(-1000000, x - k + 1)
while i <= min(1000000, x + k - 1):
  print(i, end=" ")
  i += 1