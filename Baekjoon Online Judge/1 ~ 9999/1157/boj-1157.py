str = input().upper()

cnt = [0] * 26
for ch in str:
  cnt[ord(ch) - ord('A')] += 1

maxValue = max(cnt)
if cnt.count(maxValue) == 1:
  print(chr(cnt.index(maxValue) + ord('A')))
else:
  print('?')