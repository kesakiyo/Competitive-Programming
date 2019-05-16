import sys

list = [0] * 9
sum = 0
for i in range(9):
  list[i] = int(input())
  sum += list[i]
list.sort()

for i in range(9):
  for j in range(i + 1, 9):
    if sum - list[i] - list[j] == 100:
      for k in range(9):
        if k != i and k != j:
          print(list[k])
      sys.exit(0)