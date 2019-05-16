n, target = map(int, input().split())
A = list(map(int, input().split()))

def func(pos, tot):
  if pos == n:
    return 1 if tot == target else 0
  return func(pos + 1, tot) + func(pos + 1, tot + A[pos])

ans = func(0, 0)
if target == 0:
  ans -= 1

print(ans)
