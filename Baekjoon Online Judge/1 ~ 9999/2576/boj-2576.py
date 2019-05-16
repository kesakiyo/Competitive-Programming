list = []
for _ in range(7):
  list.append(int(input()))

odds = [x for x in list if x % 2 == 1]

if not odds:
  print(-1)
else:
  print('{0}\n{1}'.format(sum(odds), min(odds)))