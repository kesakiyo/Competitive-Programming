n = int(input())

words = []
for _ in range(n):
  words.append(input())

for i in range(len(words[0])):
  s = set()
  for j in range(n):
    s.add(words[j][i])
  print(s.pop() if len(s) == 1 else '?', end = '')